/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:02:50 by abadalya          #+#    #+#             */
/*   Updated: 2021/03/19 19:02:53 by abadalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_ptr(void *p, t_form temp)
{
	int		len;
	char	*str_space;
	t_ull	ptr;
	int		ptr_size;

	ptr_size = 0;
	ptr = (t_ull)p;
	ptr_size = hex_num_size(ptr);
	len = (temp.width > ptr_size ? (temp.width - ptr_size - 2) : 0);
	str_space = fill_space(len);
	if (!temp.minus && str_space)
		ft_putstr(str_space);
	ft_putstr("0x");
	if (p)
		ft_putnbr_base(ptr, "0123456789abcdef");
	else
		ft_putchar('0');
	if (temp.minus && str_space)
		ft_putstr(str_space);
	free(str_space);
	return (2 + ptr_size + len);
}
