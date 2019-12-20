/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:07:56 by moboustt          #+#    #+#             */
/*   Updated: 2019/12/20 10:51:23 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_do_parsing(const char *fmt, va_list ap, t_struct *list, int i_pos)
{
	list->i = i_pos;
	if (!(ft_strchr(CCONVERSIONS, fmt[list->i])))
		ft__flag(fmt, list, ap, i_pos);
	else
	{
		conversion(fmt, list, ap);
		zerolistll(list);
	}
	return (list->i - 1);
}

int	handle_format(const char *fmt, va_list ap, t_struct *list, int i)
{
	while (fmt[i] != '\0')
	{
		if (fmt[i] != '%' && fmt[i])
			list->n += write(1, &fmt[i], 1);
		else if (fmt[i] == '%')
		{
			if (!ft_strchr(ALLSYMBOLS, fmt[i + 1]))
				break ;
			while (ft_strchr(ALLSYMBOLS, fmt[i + 1]))
			{
				i = i + 1;
				if (ft_strchr(CCONVERSIONS, fmt[i]))
				{
					i = ft_do_parsing(fmt, ap, list, i) + 2;
					break ;
				}
				else
					i = ft_do_parsing(fmt, ap, list, i);
			}
			continue ;
		}
		i++;
	}
	return (list->n);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_struct	*s;
	int			fmt_len;
	int			status;

	va_start(ap, fmt);
	fmt_len = ft_strlen(fmt);
	if (!(s = (t_struct*)malloc(sizeof(t_struct))))
		return (-1);
	zerolist(s);
	if (!fmt[0])
	{
		write(1, "", 1);
		return (0);
	}
	if (fmt_len == 1 && fmt[0] == '%')
		return (0);
	else
		status = handle_format(fmt, ap, s, 0);
	va_end(ap);
	free(s);
	return (status);
}
