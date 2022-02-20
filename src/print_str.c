/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:53:19 by abadalya          #+#    #+#             */
/*   Updated: 2021/03/19 19:53:21 by abadalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_str(char *str, t_form temp)
{
	int		str_size;
	char	*str_space;
	char	*final_str;

	str_space = NULL;
	final_str = NULL;
	str = null_str(str);
	str_size = ft_strlen(str);
	if (temp.length > 0)
		str_size = (temp.length < str_size ? temp.length : str_size);
	if (!(final_str = malloc(str_size + 1)))
		return (0);
	ft_strlcpy(final_str, str, str_size + 1);
	str_space = s_width(temp, str_size);
	if (!temp.length && temp.dot)
	{
		final_str = NULL;
		str_space = fill_space(temp.width);
	}
	final_str = temp.minus ? ft_strjoin(final_str, str_space) :
								ft_strjoin(str_space, final_str);
	ft_putstr(final_str);
	return (ft_strlen(final_str));
}

char	*null_str(char *str)
{
	if (!str)
	{
		if (!(str = malloc(7)))
			return (0);
		str = "(null)";
	}
	return (str);
}

char	*s_width(t_form temp, int str_size)
{
	int		len;
	char	*str_space;

	len = 0;
	str_space = NULL;
	if (temp.width)
	{
		len = temp.width - (temp.width < str_size ? temp.width : str_size);
		str_space = fill_space(len);
	}
	return (str_space);
}
