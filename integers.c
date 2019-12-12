/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:37:34 by moboustt          #+#    #+#             */
/*   Updated: 2019/12/06 18:10:08 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		is_int(t_struct *list, va_list ap)
{
	int out_int;
	int int_len;
	int refer;

	refer = 0;
	out_int = (int)va_arg(ap, int);
	int_len = ft_intlen(out_int);
	if (zero_input(list, out_int) == 1)
		return (0);
	if (list->precision == -1 && list->width == -1)
	{
		out_int < 0 ? int_len += 1 : int_len;
		list->n += write(1, ft_itoa(out_int), int_len);
	}
	else
	{
		if (out_int < 0)
		{
			refer = -1;
			out_int = -out_int;
		}
		is_int_handle(list, out_int, refer, int_len);
	}
	return (0);
}

int		zero_input(t_struct *list, int out_int)
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

void	is_int_handle(t_struct *list, int out_int, int refer, int int_len)
{
	char *s;

	s = ft_itoa(out_int);
	if (list->dot && list->precision > int_len)
		list->precision -= int_len;
	else
		list->precision = 0;
	if (refer == 0)
		list->width = list->width - (list->precision + int_len);
	else
		list->width = list->width - (list->precision + int_len + 1);
	if (list->minus == 1)
		int_righthand(list, out_int, refer, s);
	else
		int_lefthand(list, out_int, refer, s);
}

void	int_righthand(t_struct *list, int out_int, int refer, char *s)
{
	int ret;
	int int_len;

	ret = 0;
	int_len = ft_intlen(out_int);
	if (refer != 0)
		list->n += write(1, "-", 1);
	while (list->precision > 0)
	{
		list->n += write(1, "0", 1);
		list->precision--;
	}
	list->n += write(1, s, int_len);
	while (list->width > 0)
	{
		list->n += write(1, " ", 1);
		list->width--;
	}
}

void	int_lefthand(t_struct *list, int out_int, int refer, char *s)
{
	int ret;
	int rc;
	int int_len;

	ret = 0;
	rc = '\0';
	int_len = ft_intlen(out_int);
	if (list->zero && !list->dot)
		rc = '0';
	else
		rc = ' ';
	if (rc == '0' && refer != 0)
	{
		list->n += write(1, "-", 1);
		refer = 0;
	}
	while (list->width-- > 0)
		list->n += write(1, &rc, 1);
	if (refer != 0)
		list->n += write(1, "-", 1);
	while (list->precision-- > 0)
		list->n += write(1, "0", 1);
	list->n += write(1, s, int_len);
}
