/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:10:14 by abadalya          #+#    #+#             */
/*   Updated: 2021/03/19 16:10:20 by abadalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_digit(long digit, t_form temp)
{
	char	*str_space;
	char	*str_zero;
	int		minus_sign;

	str_zero = NULL;
	str_space = NULL;
	minus_sign = (digit < 0 ? 1 : 0);
	if (digit < 0)
		digit *= (-1);
	str_space = d_width(temp, digit, &minus_sign);
	str_zero = d_length(temp, digit, minus_sign);
	return (print_digit_final_str(temp, digit, str_space, str_zero));
}

char	*d_width(t_form temp, long digit, int *minus_sign)
{
	char	*str_space;
	int		len;

	str_space = NULL;
	len = 0;
	if (temp.width)
	{
		len = temp.width -
			(temp.length > num_size(digit) ? temp.length : num_size(digit));
		if (len > 0)
		{
			if (temp.zero && !temp.length && !temp.dot)
			{
				str_space = ft_calloc((len - *minus_sign), sizeof(char));
				if (*minus_sign)
				{
					str_space = ft_strjoin("-", str_space);
					*minus_sign = 0;
				}
			}
			else
				str_space = fill_space((len - *minus_sign));
		}
	}
	return (str_space);
}

char	*d_length(t_form temp, long digit, int minus_sign)
{
	char	*str_zero;
	int		len;

	len = 0;
	str_zero = NULL;
	if (temp.length)
	{
		len = temp.length -
			(temp.length < num_size(digit) ? temp.length : num_size(digit));
		str_zero = ft_calloc(len, sizeof(char));
	}
	if (minus_sign)
		str_zero = ft_strjoin("-", str_zero);
	return (str_zero);
}

int		print_digit_final_str(t_form temp,
		long digit, char *str_space, char *str_zero)
{
	char	*num;
	char	*final_str;

	final_str = NULL;
	num = ft_itoa(digit);
	if (temp.minus)
		final_str = ft_strjoin(str_zero, num);
	if (temp.minus)
		final_str = ft_strjoin(final_str, str_space);
	else
	{
		final_str = ft_strjoin(str_space, str_zero);
		final_str = ft_strjoin(final_str, num);
	}
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
