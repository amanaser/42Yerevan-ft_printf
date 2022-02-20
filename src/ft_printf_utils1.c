/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:44:50 by abadalya          #+#    #+#             */
/*   Updated: 2021/03/19 20:45:25 by abadalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		forward(const char *form, char c)
{
	int i;

	i = 0;
	if (c != '0')
	{
		while (form[i] != check_type(c))
			i++;
	}
	return (i + 1);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

char	*ft_calloc(int count, int size)
{
	char	*p;
	char	*start;

	p = malloc((count + 1) * size);
	start = p;
	if (p == 0)
		return (p);
	while (count--)
		*p++ = '0';
	*p = '\0';
	return (start);
}

int		ft_putstr(char *str)
{
	int len;

	len = 0;
	if (!str)
		return (0);
	while (*str != '\0')
	{
		write(1, str, 1);
		++len;
		str++;
	}
	return (len);
}

char	*fill_space(int size)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = malloc(size + 1)))
		return (NULL);
	while (size--)
		str[i++] = ' ';
	str[i] = '\0';
	return (str);
}
