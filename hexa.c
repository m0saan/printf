/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 20:29:34 by moboustt          #+#    #+#             */
/*   Updated: 2019/12/20 23:24:08 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.h"

char	*hexa_convert(t_struct *list, unsigned long deci, char s, char *r)
{
	unsigned long	res;

	res = 0;
	ft_memset(r, 0, 100);
	while (deci != 0)
	{
		res = deci % 16;
		if (res < 10)
			res += 48;
		else
		{
			if (s == 'A')
				res += 55;
			if (s == 'a')
				res += 87;
		}
		r[list->h++] = res;
		deci = deci / 16;
	}
	return (ft_strrev(r));
}

void	handle_widthprecision(t_struct *list, unsigned int hexa_len)
{
	if (list->dot && list->precision > (int)hexa_len)
		list->precision -= hexa_len;
	else
		list->precision = 0;
	list->width = list->width - (list->precision + hexa_len);
}

void	is_hexa(const char *fmt, t_struct *list, va_list ap)
{
	char				*tb;
	long				out_hexa;
	char				*r;

	r = malloc(100 * sizeof(char));
	out_hexa = va_arg(ap, unsigned int);
	if (zero_input(list, out_hexa) == 1)
		return ;
	else if (out_hexa == 0 && list->dot == 1 && list->width > 0 &&
	(list->precision == 0 || list->precision == -1))
		tb = "";
	else if (out_hexa == 0)
		tb = "0";
	else
		tb = hexa_convert(list, out_hexa, (fmt[list->i] == 'x') ? 'a' : 'A', r);
	if (pppp(list, ft_strlen(tb), tb) == 1)
		return ;
	else
		handle_widthprecision(list, ft_strlen(tb));
	if (fmt[list->i] == 'x')
		list->minus == 1 ? right_hexa(list, tb) : left_hexa(list, tb);
	else
		list->minus == 1 ? right_hexa(list, tb) : left_hexa(list, tb);
	free(r);
}

void	right_hexa(t_struct *list, char *tb)
{
	while (list->precision-- > 0)
		list->n += write(1, "0", 1);
	list->n += print_hexa(tb);
	while (list->width-- > 0)
		list->n += write(1, " ", 1);
}

void	left_hexa(t_struct *list, char *tb)
{
	int rc;

	rc = '\0';
	if (list->zero && !list->dot)
		rc = '0';
	else
		rc = ' ';
	while (list->width > 0)
	{
		list->n += write(1, &rc, 1);
		list->width--;
	}
	while (list->precision-- > 0)
		list->n += write(1, "0", 1);
	list->n += print_hexa(tb);
}
