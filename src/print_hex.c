/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:57:12 by abadalya          #+#    #+#             */
/*   Updated: 2021/03/19 17:57:37 by abadalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			print_hex(long num, t_form temp)
{
	char	*str_space;
	char	*str_zero;
	int		str_size;

	str_space = NULL;
	str_space = NULL;
	if (num < 0)
		num = 4294967296 + num;
	str_zero = x_length(temp, hex_num_size(num));
	str_space = x_width(temp, hex_num_size(num));
	if (!temp.length && !num && temp.dot)
	{
		if (temp.width)
			str_space = fill_space(temp.width);
		if (temp.width)
			ft_putstr(str_space);
		return (temp.width);
	}
	if (temp.type == 'X')
		print_hex_upper(temp.minus, str_zero, str_space, num);
	else if (temp.type == 'x')
		print_hex_lower(temp.minus, str_zero, str_space, num);
	str_size = (str_zero ? ft_strlen(str_zero) : 0)
		+ (str_space ? ft_strlen(str_space) : 0);
	return (str_size + hex_num_size(num));
}

void		print_hex_upper(int minus,
		char *str_zero, char *str_space, long num)
{
	if (minus)
	{
		ft_putstr(str_zero);
		ft_putnbr_base(num, "0123456789ABCDEF");
		ft_putstr(str_space);
	}
	else
	{
		ft_putstr(str_space);
		ft_putstr(str_zero);
		ft_putnbr_base(num, "0123456789ABCDEF");
	}
}

void		print_hex_lower(int minus,
		char *str_zero, char *str_space, long num)
{
	if (minus)
	{
		ft_putstr(str_zero);
		ft_putnbr_base(num, "0123456789abcdef");
		ft_putstr(str_space);
	}
	else
	{
		ft_putstr(str_space);
		ft_putstr(str_zero);
		ft_putnbr_base(num, "0123456789abcdef");
	}
}

char		*x_width(t_form temp, int num_size)
{
	int		len;
	char	*str_space;

	len = 0;
	str_space = NULL;
	if (temp.width)
	{
		len = temp.width - (temp.length > num_size ? temp.length : num_size);
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

char		*x_length(t_form temp, int num_size)
{
	int		len;
	char	*str_zero;

	str_zero = NULL;
	if (temp.length)
		len = temp.length - (temp.length < num_size ? temp.length : num_size);
	if (temp.length)
		str_zero = ft_calloc(len, sizeof(char));
	return (str_zero);
}
