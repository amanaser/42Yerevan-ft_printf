/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:45:53 by abadalya          #+#    #+#             */
/*   Updated: 2021/03/19 21:59:11 by abadalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			ft_putnbr_base(t_ull nbr, char *base)
{
	int			size;
	t_ull		num;
	static int	count = 0;

	size = 0;
	num = nbr;
	if (!checkbase(base))
		return (0);
	while (base[size] != '\0')
		size++;
	if (num < 0)
	{
		num = num * (-1);
		ft_putchar('-');
	}
	if (num >= (t_ull)size)
	{
		ft_putnbr_base(num / size, base);
		ft_putnbr_base(num % size, base);
	}
	else
		count += ft_putchar(base[num]);
	return (count);
}

t_form		initialize_struct(void)
{
	t_form t;

	t.zero = 0;
	t.minus = 0;
	t.width = 0;
	t.dot = 0;
	t.length = 0;
	t.type = '0';
	return (t);
}

t_form		initialize_flags(const char *form, int *i)
{
	t_form flags;

	flags = initialize_struct();
	if ((flags.minus = check_minus(form[*i])) == 1)
		(*i)++;
	if ((flags.zero = check_zero(form[*i])) == 1)
		(*i)++;
	if (check_minus(form[*i]) == 1)
	{
		flags.minus = 1;
		(*i)++;
	}
	return (flags);
}
