/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:45:30 by abadalya          #+#    #+#             */
/*   Updated: 2021/03/19 20:46:23 by abadalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

int		len(long n)
{
	int len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int		num_size(int num)
{
	int size;

	size = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		num *= -1;
	while (num)
	{
		num /= 10;
		size++;
	}
	return (size);
}

int		hex_num_size(t_ull num)
{
	int len;

	len = 0;
	if (num == 0)
		len++;
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

int		ft_strlcpy(char *dest, const char *src, int size)
{
	int i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
