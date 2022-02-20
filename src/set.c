/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaghdas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:14:28 by dbaghdas          #+#    #+#             */
/*   Updated: 2021/03/08 15:14:52 by dbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		set_arg_type(t_form temp, va_list list)
{
	int bytes;

	bytes = 0;
	if (temp.type == 'd' || temp.type == 'i')
		bytes = print_digit(va_arg(list, int), temp);
	else if (temp.type == 'c')
		bytes = print_char(va_arg(list, int), temp);
	else if (temp.type == 's')
		bytes = print_str(va_arg(list, char*), temp);
	else if (temp.type == 'p')
		bytes = print_ptr(va_arg(list, void*), temp);
	else if (temp.type == 'u')
		bytes = print_unsigned_int(va_arg(list, unsigned int), temp);
	else if (temp.type == 'x' || temp.type == 'X')
		bytes = print_hex(va_arg(list, int), temp);
	else if (temp.type == '%')
		bytes = print_percent(temp);
	return (bytes);
}
