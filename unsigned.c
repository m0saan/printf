/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 13:31:03 by moboustt          #+#    #+#             */
/*   Updated: 2019/12/07 13:34:04 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		zero_input_u(t_struct *list, unsigned int out_int)
{
	if (out_int == 0 && list->dot == 1 && list->width > 0 &&
	(list->precision == -1 || list->precision == 0))
	{
		while (list->width-- > 0)
			list->n += write(1, " ", 1);
		return (1);
	}
	else if (out_int == 0 && list->dot == 1 &&
		(list->precision == 0 || list->precision == -1))
	{
		write(1, "", 1);
		return (1);
	}
	return (0);
}

int		is_unsigned(t_struct *list, va_list ap)
{
	unsigned int	out_unsigned;
	unsigned int	unsigned_len;
	char			*s;

	out_unsigned = (unsigned int)va_arg(ap, unsigned int);
	unsigned_len = ft_intlen(out_unsigned);
	s = ft_itoa(out_unsigned);
	if (zero_input(list, out_unsigned) == 1)
		return (0);
	if (list->width == -1 && list->precision == -1)
	{
		list->n += write(1, s, unsigned_len);
		return (0);
	}
	else
	{
		widthprecisionhandle(list, unsigned_len);
		if (list->minus == 1)
			unsigned_rightparese(list, s, unsigned_len);
		else
			unsigned_leftparese(list, s, unsigned_len);
	}
	return (0);
}

void	widthprecisionhandle(t_struct *list, unsigned int unsigned_len)
{
	if (list->dot && list->precision > (int)unsigned_len)
		list->precision -= unsigned_len;
	else
		list->precision = 0;
	list->width = list->width - (list->precision + unsigned_len);
}

void	unsigned_rightparese(t_struct *list, char *s, unsigned int unsigned_len)
{
	while (list->precision-- > 0)
		list->n += write(1, "0", 1);
	list->n += write(1, s, unsigned_len);
	while (list->width-- > 0)
		list->n += write(1, " ", 1);
}

void	unsigned_leftparese(t_struct *list, char *s, unsigned int unsigned_len)
{
	int rc;

	rc = '\0';
	if (list->zero && !list->dot)
		rc = '0';
	else
		rc = ' ';
	while (list->width-- > 0)
		list->n += write(1, &rc, 1);
	while (list->precision-- > 0)
		list->n += write(1, "0", 1);
	list->n += write(1, s, unsigned_len);
}
