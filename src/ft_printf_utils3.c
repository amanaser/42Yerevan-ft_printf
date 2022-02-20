/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:45:42 by abadalya          #+#    #+#             */
/*   Updated: 2021/03/19 20:45:44 by abadalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_atoi(const char *format, int *i)
{
	long		result;
	const char	*str;

	result = 0;
	str = format;
	while (*str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\f'
			|| *str == '\r' || *str == ' ')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + ((*str) - '0');
		str++;
		(*i)++;
	}
	return (result);
}

char	*ft_itoa(long num)
{
	char	*p;
	int		l;

	l = len(num);
	if (!(p = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	if (num == 0)
		p[0] = '0';
	else if (num < 0)
	{
		p[0] = '-';
		num *= -1;
	}
	p[l--] = '\0';
	while (num)
	{
		p[l] = num % 10 + '0';
		l--;
		num /= 10;
	}
	return (p);
}

char	*ft_uitoa(t_ui n)
{
	t_ull	number;
	char	*array;
	size_t	size;

	number = n;
	size = ulen(n);
	if (!(array = (char *)malloc(size + 1)))
		return (NULL);
	array[size] = '\0';
	while (1)
	{
		array[size - 1] = (number % 10) + '0';
		number /= 10;
		size--;
		if (number == 0)
			break ;
	}
	return (array);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (char*)(!s1 ? s2 : s1);
	if (!(str = (char *)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (++i < ft_strlen(s1))
		str[i] = s1[i];
	j = 0;
	while (j < ft_strlen(s2))
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

int		checkbase(char *str)
{
	int i;
	int j;

	i = 0;
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
