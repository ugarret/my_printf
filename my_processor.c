#include "my_printf.h"

int		my_processor(t_parsing *option, va_list ap)
{
	int i;

	i = 0;
	if (option->type == 'd' || option->type == 'i')
		return (my_type_d_and_i(option, ap, i));
	if (option->type == 'u')
		return (my_type_u(option, ap, i));
	if (option->type == 'x' || option->type == 'X')
		return (my_type_x(option, ap, i));
	if (option->type == 'c' || option->type == '%')
		return (my_type_c_and_percent(option, ap, i));
	if (option->type == 's')
		return (my_type_s(option, ap, i));
	if (option->type == 'p')
		return (my_type_p(option, ap, i));
	return (0);
}

int		my_print_space(t_parsing *option, int len, int i)
{
	if (option->flag_p && !option->precision && len)
		option->width++;
	while (option->width > len && option->width > option->precision)
	{
		write(1, " ", 1);
		i++;
		option->width--;
	}
	return (i);
}

int		my_print_zero(t_parsing *option, int len, int i)
{
	if (option->flag_z && option->width > option->precision)
		option->precision = option->width;
	while (option->precision > len)
	{
		write(1, "0", 1);
		i++;
		option->precision--;
		option->width--;
	}
	return (i);
}

int		my_print_number_or_word(char *str, int i)
{
	int j;

	j = 0;
	while (str[j] != '\0')
	{
		write(1, &str[j++], 1);
		i++;
	}
	free(str);
	str = NULL;
	return (i);
}

int		my_print_minus(t_parsing *option, int i)
{
	write(1, "-", 1);
	i++;
	option->width--;
	return (i);
}
