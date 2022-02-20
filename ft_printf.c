#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
	va_list 	list;
	t_form  	temp;
	int     	bytes;
	int			i;
	const char  *form;

	i = 0;
	bytes = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			++i;
			form = format + i;
			temp = checks(form, list);
			i += forward(form, temp.type);
			bytes += set_arg_type(temp, list);
		}
		else
		{
			bytes += ft_putchar(format[i]);
			++i;
		}
	}
	va_end(list);
	return (bytes);
}