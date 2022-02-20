/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:37:32 by abadalya          #+#    #+#             */
/*   Updated: 2021/03/19 20:37:39 by abadalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_unsigned_int(t_ui digit, t_form temp)
{
	char	*str_space;
	char	*str_zero;
	char	*num;
	char	*final_str;

	str_zero = NULL;
	str_space = NULL;
	num = ft_uitoa(digit);
	str_zero = u_length(temp, digit);
	str_space = u_width(temp, digit);
	final_str = join_final_str(temp.minus, str_space, str_zero, num);
	if (!temp.length && !digit && temp.dot)
	{
		if (temp.width)
		{
			str_space = fill_space(temp.width);
			ft_putstr(str_space);
		}
		return (temp.width);
	}
	ft_putstr(final_str);
	return (ft_strlen(final_str));
}

int		ulen(t_ui n)
{
	int len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*u_width(t_form temp, t_ui digit)
{
	int		len;
	char	*str_space;

	len = 0;
	str_space = NULL;
	if (temp.width)
	{
		len = temp.width -
			(temp.length > ulen(digit) ? temp.length : ulen(digit));
		if (len > 0)
		{
			if (temp.zero && !temp.dot && !temp.length)
				str_space = ft_calloc(len, sizeof(char));
			else
				str_space = fill_space(len);
		}
	}
	return (str_space);
}

char	*u_length(t_form temp, t_ui digit)
{
	int		len;
	char	*str_zero;

	len = 0;
	str_zero = NULL;
	if (temp.length)
	{
		len = temp.length -
			(temp.length < ulen(digit) ? temp.length : ulen(digit));
		str_zero = ft_calloc(len, sizeof(char));
	}
	return (str_zero);
}

char	*join_final_str(int temp_minus, char *str_space,
			char *str_zero, char *num)
{
	char	*final_str;

	final_str = NULL;
	if (temp_minus)
	{
		final_str = ft_strjoin(str_zero, num);
		final_str = ft_strjoin(final_str, str_space);
	}
	else
	{
		final_str = ft_strjoin(str_space, str_zero);
		final_str = ft_strjoin(final_str, num);
	}
	return (final_str);
}
