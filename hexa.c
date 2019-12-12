/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexaa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:26:39 by moboustt          #+#    #+#             */
/*   Updated: 2019/12/06 18:48:59 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
int    zero_input_x(t_struct *list, long out_hexa)
{
    if (out_hexa == 0 && list->dot == 1 && list->width > 0 && (list->precision == -1 || list->precision == 0))
    {
        while (list->width-- > 0)
            list->n += write(1," ",1);
        return (1);
    }
    else if (out_hexa == 0 && list->dot == 1 && (list->precision == 0 || list->precision == -1))
    {
        write(1,"",1);
        return (1);
    }
    return (0);
}
int     print_hexa(char *tb)
{
    unsigned int ret;
    int i;

    i = 0;
    ret = 0;
    if (ft_strlen(tb) != 0)
    {
        while(tb[i] != '\0')
            ret += write(1, &tb[i++] ,1);
    }
    return (ret);
}
char    *hexa_convert(t_struct *list, unsigned long deci, char s)
{
    char tb[100];
    char *r;
    unsigned long res;

    res = 0;
    while (deci != 0)
    {
        res = deci % 16;
        if (res < 10)
            res += 48;
        else
        {
            if (s == 'A')
                res += 55;
            if (s == 'a')
                res += 87;
        }
        tb[list->h++] = res;
        deci = deci / 16;
    }
    tb[list->h] = '\0';
    r = ft_strdup(tb);
    return (ft_strrev(r));
}
void    handle_widthprecision(t_struct *list, unsigned int hexa_len)
{
    if (list->dot && list->precision > (int)hexa_len)
        list->precision -= hexa_len;
    else
        list->precision = 0;
    list->width = list->width - (list->precision + hexa_len);
}
int is_hexa(const char *fmt, t_struct *list, va_list ap)
{
    unsigned int hexa_len;
    char *tb;
    long out_hexa;

    out_hexa = va_arg(ap, unsigned int);
    if (zero_input(list, out_hexa) == 1)
        return (0);
    else if (out_hexa == 0 && list->dot == 1 && list->width > 0 &&  (list->precision == 0 || list->precision == -1))
        tb = "";
    else if (out_hexa == 0)
        tb = "0";
    else
        tb = hexa_convert(list, out_hexa, (fmt[list->i] == 'x') ? 'a' : 'A');
    hexa_len =  ft_strlen(tb);
    if (list->width == -1 && list->precision == -1)
    {
        list->n += write(1,tb,hexa_len);
        return (0);
    }
    else
        handle_widthprecision(list, hexa_len);
    if (fmt[list->i] == 'x')
        list->minus == 1 ? right_hexa_flags(list, tb) : left_hexa_flags(list, tb);
    else
        list->minus == 1 ? right_hexa_flags(list, tb) : left_hexa_flags(list, tb);
    return (0);
}
void right_hexa_flags(t_struct *list, char *tb)
{
    while (list->precision-- > 0)
        list->n += write(1,"0",1);
    list->n += print_hexa(tb);
    while (list->width-- > 0)
        list->n += write(1," ",1);
}
void     left_hexa_flags(t_struct *list, char *tb)
{
    int rc;

    rc = '\0';
    if (list->zero && !list->dot)
        rc = '0';
    else
        rc = ' ';
    while (list->width > 0)
    {
        list->n += write(1, &rc ,1);
        list->width--;
    }
    while (list->precision-- > 0)
        list->n += write(1,"0",1);
    list->n += print_hexa(tb);
}
