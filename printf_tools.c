/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 20:21:19 by moboustt          #+#    #+#             */
/*   Updated: 2019/12/12 20:21:27 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	zerolist(t_struct *list)
{
	list->n = 0;
	list->h = 0;
	list->i = 0;
	list->width = -1;
	list->minus = 0;
	list->zero = 0;
	list->dot = 0;
	list->precision = -1;
	list->asterisk = 0;
}

void	zerolistll(t_struct *list)
{
	list->h = 0;
	list->width = 0;
	list->minus = 0;
	list->zero = 0;
	list->dot = 0;
	list->precision = 0;
	list->asterisk = 0;
}

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	ch;

	j = 0;
	i = 0;
	while (str[i] != '\0')
		i++;
	i = i - 1;
	while (j < i)
	{
		ch = str[j];
		str[j] = str[i];
		str[i] = ch;
		j++;
		i--;
	}
	return (str);
}

int		ft_intlen(long x)
{
	if (x < 0)
		x = -x;
	if (x >= 1000000000)
		return (10);
	if (x >= 100000000)
		return (9);
	if (x >= 10000000)
		return (8);
	if (x >= 1000000)
		return (7);
	if (x >= 100000)
		return (6);
	if (x >= 10000)
		return (5);
	if (x >= 1000)
		return (4);
	if (x >= 100)
		return (3);
	if (x >= 10)
		return (2);
	return (1);
}

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
