/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:14:16 by moboustt          #+#    #+#             */
/*   Updated: 2019/12/12 14:14:39 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	goto_percent(t_struct *list)
{
	int rc;

	rc = ' ';
	if (list->minus == 0)
	{
		if (list->zero == 1)
			rc = '0';
		while (list->width-- > 1)
			list->n += write(1, &rc, 1);
		list->n += write(1, "%", 1);
	}
	else
	{
		list->n += write(1, "%", 1);
		while (list->width-- > 1)
			list->n += write(1, " ", 1);
	}
	return (0);
}
