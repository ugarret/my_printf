#include "my_printf.h"

int		my_printf(const char *format, ...)
{
	int			i;
	va_list		ap;
	t_parsing	option;

	i = 0;
	option.count = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (format[i] != '\0')
		if (format[i] == '%')
		{
			my_initialization(&option);
			if ((i = my_work_arg(i, format, &option, ap)) == -1)
				return (-1);
		}
		else
		{
			write(1, &format[i++], 1);
			option.count++;
		}
	va_end(ap);
	return (option.count);
}

void	my_initialization(t_parsing *option)
{
	option->flag_z = 0;
	option->flag_m = 0;
	option->flag_p = 0;
	option->flag_s = 0;
	option->width = 0;
	option->precision = 0;
	option->type = 0;
}

int		my_work_arg(int i, const char *f, t_parsing *option, va_list ap)
{
	int	j;

	if ((i = my_parser(++i, f, option, ap)) == -1)
	{
		va_end(ap);
		return (-1);
	}
	if ((j = my_processor(option, ap)) == -1)
	{
		va_end(ap);
		return (-1);
	}
	else
		option->count += j;
	return (i);
}
