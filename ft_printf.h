/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:31:34 by abadalya          #+#    #+#             */
/*   Updated: 2021/03/19 22:37:18 by abadalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef unsigned long long int	t_ull;
typedef unsigned int			t_ui;
typedef long long int			t_ll;
typedef struct					s_form
{
	int							zero;
	int							minus;
	int							width;
	int							dot;
	int							length;
	char						type;
}								t_form;
int								ft_printf(const char *format, ...);
t_form							checks(const char *form, va_list vl);
t_form							initialize_struct(void);
int								check_zero(char c);
int								check_minus(char c);
int								num_size(int num);
int								len(long n);
int								ulen(t_ui num);
int								check_width_length(const char *form,
									va_list vl, int *i);
int								ft_atoi(const char *format, int *i);
char							check_type(char c);
int								forward(const char *form, char c);
int								ft_putchar(char c);
int								set_arg_type(t_form temp, va_list list);
char							*ft_calloc(int count, int size);
int								ft_putstr(char *str);
char							*ft_itoa(long num);
char							*ft_uitoa(t_ui n);
int								ft_strlen(const char *s);
char							*ft_strjoin(char const *s1, char const *s2);
char							*fill_space(int size);
int								print_digit(long digit, t_form temp);
int								print_char(char c, t_form temp);
int								print_str(char *str, t_form temp);
int								print_ptr(void *p, t_form temp);
int								print_unsigned_int(t_ui num, t_form temp);
int								ft_strlcpy(char *dest,
									const char *src, int size);
int								checkbase(char *str);
int								ft_putnbr_base(t_ull nbr, char *base);
int								hex_num_size(t_ull num);
int								print_hex(long num, t_form temp);
void							print_hex_upper(int minus,
									char *str_zero, char *str_space,
									long num);
void							print_hex_lower(int minus,
									char *str_zero, char *str_space,
									long num);
int								print_percent(t_form temp);
char							*d_width(t_form temp,
									long digit, int *minus_sign);
char							*d_length(t_form temp,
									long digit, int minus_sign);
int								print_digit_final_str(t_form temp, long digit,
									char *str_space, char *str_zero);
char							*x_width(t_form temp, int num_size);
char							*x_length(t_form temp, int num_size);
int								print_percent_final_str(t_form temp,
									char *str_space, char *str_zero);
char							*percent_width(t_form temp);
char							*null_str(char *str);
char							*s_width(t_form temp, int str_size);
char							*u_width(t_form temp, t_ui digit);
char							*u_length(t_form temp, t_ui digit);
char							*join_final_str(int temp_minus,
									char *str_space, char *str_zero, char *num);
t_form							initialize_flags(const char *form, int *i);

#endif
