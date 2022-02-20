/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:13:41 by abadalya          #+#    #+#             */
/*   Updated: 2021/03/19 20:13:44 by abadalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_char(char c, t_form temp)
{
	char	*str_space;
	int		count;

	count = 1;
	str_space = NULL;
	if (temp.width)
		str_space = fill_space(temp.width - 1);
	if (temp.minus)
	{
		ft_putchar(c);
		ft_putstr(str_space);
	}
	else
	{
		ft_putstr(str_space);
		ft_putchar(c);
	}
	count += str_space ? ft_strlen(str_space) : 0;
	free(str_space);
	return (count);
}
