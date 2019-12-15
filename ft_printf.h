/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:11:08 by moboustt          #+#    #+#             */
/*   Updated: 2019/12/15 21:49:14 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# define CCONVERSIONS 	"cspdiuxX%"
# define CFLAGS 		"-.*0123456789"
# define ALLSYMBOLS "cspdiuxX%-.*0123456789"

typedef struct	s_struct
{
	int			n;
	int			h;
	int			i;
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			precision;
	int			asterisk;
}				t_struct;

int				ft_printf(const char *fmt, ...);
void			ft__flag(const char *fmt, t_struct *list,
va_list ap, int i);
void			conversion(const char *fmt, t_struct *list, va_list ap);
void			is_int_handle(t_struct *list, int out_int,
int refer, int int_len);
int				is_int(t_struct *list, va_list ap);
void			is_char(t_struct *list, va_list ap);
int				is_string(t_struct *list, va_list ap);
void			goto_right(t_struct *list, char *out_str, int str_len);
void			goto_left(t_struct *list, char *out_str, int str_len);
void			specify_widthprecision(t_struct *list, char *out_str,
int str_len);
int				is_hexa(const char *fmt, t_struct *list, va_list ap);
int				is_pointer(t_struct *list, va_list ap);
void			handle_widthprecision(t_struct *list,
unsigned int hexa_len);
int				is_unsigned(t_struct *list, va_list ap);
void			widthprecisionhandle(t_struct *list,
unsigned int unsigned_len);
void			unsigned_rightparese(t_struct *list, char *s,
unsigned int unsigned_len);
void			unsigned_leftparese(t_struct *list, char *s,
unsigned int unsigned_len);
int				goto_percent(t_struct *list);
int				print_flag_char(t_struct *list, int kind);
int				pppp(t_struct *list, unsigned int hexa_len, char *tb);
int				print_flag_str(t_struct *list, char *out_str, int kind);
char			*hexa_convert(t_struct *list, unsigned long hexa_len, char s);
void			int_righthand(t_struct *list, int out_int, int refer, char *s);
void			int_lefthand(t_struct *list, int out_int, int refer, char *s);
void			print_base(const char *fmt, t_struct *list, int i_pos);
int				zero_input(t_struct *list, int out_int);
int				zero_input_u(t_struct *list, unsigned int out_int);
int				zero_input_x(t_struct *list, long out_hexa);
int				zero_input_p(t_struct *list, void *out_pointer);
void			left_hexa(t_struct *list, char *tb);
void			right_hexa(t_struct *list, char *tb);
void			zerolist(t_struct *list);
void			zerolistll(t_struct *list);
int				print_hexa(char *tb);
char			*ft_strrev(char *str);
int				ft_intlen(long x);
void			if_null(t_struct *list, void *s);
size_t			ft_strlen(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_itoa(long n);
int				ft_atoi(const char *s);

#endif
