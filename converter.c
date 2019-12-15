/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:22:27 by moboustt          #+#    #+#             */
/*   Updated: 2019/12/15 21:29:32 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion(const char *fmt, t_struct *list, va_list ap)
{
	if (fmt[list->i] == 'd' || fmt[list->i] == 'i')
		is_int(list, ap);
	else if (fmt[list->i] == 'c')
		is_char(list, ap);
	else if (fmt[list->i] == 's')
		is_string(list, ap);
	else if (fmt[list->i] == 'X' || fmt[list->i] == 'x')
		is_hexa(fmt, list, ap);
	else if (fmt[list->i] == 'p')
		is_pointer(list, ap);
	else if (fmt[list->i] == 'u')
		is_unsigned(list, ap);
	else
		goto_percent(list);
}
