/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 11:02:51 by moboustt          #+#    #+#             */
/*   Updated: 2019/12/20 11:03:11 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_res(char const *str, int i)
{
	long	result;

	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result);
}

int		ft_atoi(const char *s)
{
	int		i;
	int		rc;
	char	*str;

	i = 0;
	rc = 0;
	str = (char *)s;
	if (!*str)
		return (0);
	while ((str[i] >= 0 && str[i] <= 26) || (str[i] >= 28 && str[i] <= 32))
		i++;
	if (str[i] == '\e')
		return (0);
	if (str[i] == '-')
		rc = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (rc == 1)
		return (-ft_res(str, i));
	return (ft_res(str, i));
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (s[i] == c)
			return (&str[i]);
		i++;
	}
	if (s[i] == (char)c)
		return (&str[i]);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[j])
		j++;
	if (!(str = malloc(j + 1)))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (char *)(str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int			s1_len;
	int			s2_len;
	char		*new_alloc;
	int			i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	if (!(new_alloc = malloc(s1_len + s2_len + 1)))
		return (NULL);
	while (s1[i])
	{
		new_alloc[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		new_alloc[i] = s2[i - s1_len];
		i++;
	}
	new_alloc[i] = '\0';
	return ((char *)new_alloc);
}
