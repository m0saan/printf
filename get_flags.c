/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:46:21 by moboustt          #+#    #+#             */
/*   Updated: 2019/12/05 18:05:09 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
void    if_star(const char *fmt, t_struct *list, va_list ap)
{
    if (fmt[list->i] == '*')
    {
        list->width = va_arg(ap, int);
        list->asterisk = 1;
        if (list->width < 0)
        {
            list->minus = 1;
            list->width = -(list->width);
        }
        while (fmt[list->i] == '*')
            list->i++;
    }
}
void    flag(const char *fmt, t_struct *list)
{
    while (ft_strchr("-0", fmt[list->i]))
    {
        if (fmt[list->i] == '-')
            list->minus = 1;
        else if (fmt[list->i] == '0')
            list->zero = 1;
        list->i++;
    }
}
void    width(const char *fmt, t_struct *list, va_list ap)
{
    if_star(fmt, list, ap);
    if (ft_strchr("0123456789", fmt[list->i]))
    {
        list->width = ft_atoi(&fmt[list->i]);
        while (fmt[list->i] >= 48 && fmt[list->i] <= 57)
        {
            list->i++;
            if (fmt[list->i] == '*')
            {
                list->asterisk = 1;
                if (list->width < 0)
                {
                    list->minus = 1;
                    list->width = -(list->width);
                }
                while (fmt[list->i] == '*')
                    list->i++;
            }
        }
    }
}

void    precision(const char *fmt, t_struct *list, va_list ap, int p)
{
    if (fmt[list->i] == '.')
    {
        list->i++;
        list->dot = 1;
    }
    if (fmt[list->i] >= 48 && fmt[list->i] <= 57)
    {
        list->precision = ft_atoi(&fmt[list->i]);
        while (fmt[list->i] >= 48 && fmt[list->i] <= 57)
            list->i++;
    }
    else if(fmt[list->i] == '*')
    {
        p = va_arg(ap, int);
        if (p < 0 && fmt[list->i + 1] == 's')
            list->precision = -1;
        if (p >= 0)
            list->precision = p;
        else
            list->dot = 0;
        while (fmt[list->i] == '*')
            list->i++;
    }
}

void    ft__flag(const char *fmt, t_struct *list, va_list ap, int i)
{
    flag(fmt, list);
    width(fmt, list, ap);
    precision(fmt, list, ap, i);
}
