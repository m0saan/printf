/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:56:07 by moboustt          #+#    #+#             */
/*   Updated: 2019/12/06 14:32:29 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	is_char(t_struct *list, va_list ap)
{
	int out_char;

	out_char = (int)va_arg(ap, int);
	if (list->width == -1)
		list->n += write(1, &out_char, 1);
	else
	{
		if (list->minus == 1)
		{
			list->n += write(1, &out_char, 1);
			while (list->width-- > 1)
				list->n += write(1, " ", 1);
		}
		else
		{
			while (list->width-- > 1)
				list->n += write(1, " ", 1);
			list->n += write(1, &out_char, 1);
		}
	}
}
