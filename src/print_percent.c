/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:14:04 by abadalya          #+#    #+#             */
/*   Updated: 2021/03/19 20:14:36 by abadalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_percent(t_form temp)
{
	char	*str_space;
	int		count;

	count = 1;
	str_space = NULL;
	if (temp.width && !temp.zero)
		str_space = fill_space(temp.width - 1);
	if (temp.width && temp.zero)
		str_space = ft_calloc(temp.width - 1, sizeof(char));
	if (temp.minus)
	{
		ft_putchar('%');
		ft_putstr(str_space);
	}
	else
	{
		ft_putstr(str_space);
		ft_putchar('%');
	}
	count += str_space ? ft_strlen(str_space) : 0;
	free(str_space);
	return (count);
}
