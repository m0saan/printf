/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 18:36:25 by moboustt          #+#    #+#             */
/*   Updated: 2019/12/15 21:28:35 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_string(t_struct *list, va_list ap)
{
	char	*out_str;
	int		str_len;

	out_str = (char *)va_arg(ap, char*);
	if (out_str == NULL)
		out_str = "(null)";
	str_len = ft_strlen(out_str);
	if (str_len == 0)
		out_str = ft_strdup("");
	if (list->width == -1 && list->precision == -1 && !list->dot)
	{
		list->n += write(1, out_str, str_len);
		return (0);
	}
	else
	{
		if (list->minus == 1)
			goto_right(list, out_str, str_len);
		else
			goto_left(list, out_str, str_len);
	}
	return (0);
}

void	goto_right(t_struct *list, char *out_str, int str_len)
{
	if (list->precision > 0 && str_len == 0)
		list->precision = 0;
	if ((list->precision > 0 || list->precision == -1) && list->dot == 1)
		list->n += write(1, out_str, list->precision);
	else
		list->n += write(1, out_str, str_len);
	if (list->precision > str_len)
		list->precision = str_len;
	else if (list->dot == 0)
		list->width -= str_len;
	while (list->width > list->precision && list->width > 0)
	{
		list->n += write(1, " ", 1);
		list->width--;
	}
}

void	goto_left(t_struct *list, char *out_str, int str_len)
{
	if (list->dot && str_len > list->precision)
		str_len = list->precision;
	if (list->dot == 1)
		list->precision == -1 ? str_len = 0 : str_len;
	if (list->width > str_len)
	{
		while ((list->width - str_len) > 0)
		{
			list->n += write(1, " ", 1);
			list->width--;
		}
	}
	if (str_len != 0)
	{
		if (list->precision > str_len)
			list->precision = str_len;
		if ((list->precision > 0 || list->precision == -1) && list->dot == 1)
			list->n += write(1, out_str, list->precision);
		else
			list->n += write(1, out_str, str_len);
	}
}
