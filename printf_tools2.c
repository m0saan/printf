/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tools2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 21:56:57 by moboustt          #+#    #+#             */
/*   Updated: 2019/12/20 09:54:54 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		zero_input_x(t_struct *list, long out_hexa)
{
	if (out_hexa == 0 && list->dot == 1 && list->width > 0 &&
	(list->precision == -1 || list->precision == 0))
	{
		while (list->width-- > 0)
			list->n += write(1, " ", 1);
		return (1);
	}
	else if (out_hexa == 0 && list->dot == 1 &&
		(list->precision == 0 || list->precision == -1))
	{
		write(1, "", 1);
		return (1);
	}
	return (0);
}

int		print_hexa(char *tb)
{
	unsigned int	ret;
	int				i;

	i = 0;
	ret = 0;
	if (ft_strlen(tb) != 0)
	{
		while (tb[i] != '\0')
			ret += write(1, &tb[i++], 1);
	}
	return (ret);
}

void	if_zero(t_struct *list, unsigned int out_hexa, char *tb)
{
	if (out_hexa == 0 && list->dot == 1 && list->width > 0 &&
	(list->precision == 0 || list->precision == -1))
		tb = "";
	else if (out_hexa == 0)
		tb = "0";
}

int		pppp(t_struct *list, unsigned int hexa_len, char *tb)
{
	if (list->width == -1 && list->precision == -1)
	{
		list->n += write(1, tb, hexa_len);
		return (1);
	}
	return (0);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*bb;

	i = 0;
	bb = b;
	while (i < len)
	{
		bb[i] = c;
		i++;
	}
	return (bb);
}
