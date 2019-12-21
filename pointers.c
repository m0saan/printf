/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:10:32 by moboustt          #+#    #+#             */
/*   Updated: 2019/12/20 23:26:50 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		zero_input_p(t_struct *list, void *out_pointer)
{
	if (out_pointer == 0 && list->dot == 1 && list->width > 0
	&& (list->precision == -1 || list->precision == 0))
	{
		while (list->width-- > 0)
			list->n += write(1, " ", 1);
		return (1);
	}
	else if (out_pointer == 0 && list->dot == 1
	&& (list->precision == 0 || list->precision == -1))
	{
		list->n += write(1, "0x", 2);
		return (1);
	}
	return (0);
}

void	is_pointer(t_struct *list, va_list ap)
{
	void	*out_pointer;
	char	*tb;
	int		pointer_len;
	char	*r;

	r = malloc(100 * sizeof(char));
	out_pointer = va_arg(ap, unsigned long *);
	tb = hexa_convert(list, (unsigned long)out_pointer, 'a', r);
	if ((out_pointer == 0 || out_pointer == NULL) && !list->dot)
		tb = "0";
	tb = ft_strjoin("0x", tb);
	pointer_len = ft_strlen(tb);
	if (list->precision == -1 && list->width == -1)
		list->n += print_hexa(tb);
	else
	{
		handle_widthprecision(list, pointer_len);
		if (list->minus == 1)
			right_hexa(list, tb);
		else
			left_hexa(list, tb);
	}
	free(r);
	free(tb);
}
