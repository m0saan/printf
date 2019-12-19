/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 22:03:20 by moboustt          #+#    #+#             */
/*   Updated: 2019/12/18 22:52:57 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_neg(long n)
{
	int					i;
	unsigned long		sign;
	int					n_len;
	char				*alloced_mem;

	i = 0;
	sign = -n;
	n_len = ft_intlen(n);
	if (!(alloced_mem = malloc(n_len * sizeof(char) + 2)))
		return (NULL);
	alloced_mem[0] = '-';
	while (n_len > i)
	{
		alloced_mem[n_len] = sign % 10 + '0';
		sign /= 10;
		n_len--;
	}
	alloced_mem[ft_intlen(n) + 1] = '\0';
	return ((char *)alloced_mem);
}

char		*ft_itoa(long n)
{
	int			i;
	int			n_len;
	char		*alloced_mem;

	i = 0;
	if (n < 0)
		return (ft_itoa_neg(n));
	n_len = ft_intlen(n);
	if (n >= 0)
		if (!(alloced_mem = malloc(n_len * sizeof(char) + 1)))
			return (NULL);
	while (n_len > 0)
	{
		alloced_mem[n_len - 1] = n % 10 + '0';
		n /= 10;
		n_len--;
		i++;
	}
	alloced_mem[i] = '\0';
	return (char *)(alloced_mem);
}
