#include "my_printf.h"

int		my_type_c_and_percent(t_parsing *option, va_list ap, int i)
{
	char	x;
	int		len;

	len = 1;
	if (option->type == '%')
		x = '%';
	else
		x = (char)va_arg(ap, int);
	if (option->flag_m && !option->flag_z)
		option->precision = len;
	if (option->flag_p && !option->precision)
		option->width--;
	if (!option->flag_m && !option->flag_z)
		i = my_print_space(option, len, i);
	if (option->type == '%' && option->flag_z)
		i = my_print_zero(option, len, i);
	write(1, &x, 1);
	i++;
	if (option->flag_m)
		i = my_print_space(option, len, i);
	return (i);
}

int		my_type_s(t_parsing *option, va_list ap, int i)
{
	char	*x;
	char	*str;
	int		len;

	if (!(x = (char *)va_arg(ap, long int)))
		x = "(null)";
	len = my_strlen(x);
	if (option->flag_p && !option->precision)
		len = 0;
	if (option->precision > 0 && option->precision < len)
		len = option->precision;
	else if (option->precision > len && option->width)
		option->precision = len;
	if (!(option->flag_p && !option->precision))
		if (!(str = my_duplicate(x, &len)))
			return (-1);
	if (!option->flag_m)
		i = my_print_space(option, len, i);
	if (!(option->flag_p && !option->precision))
		i = my_print_number_or_word(str, i);
	else
		str = NULL;
	if (option->flag_m)
		i = my_print_space(option, len, i);
	return (i);
}

int		my_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*my_duplicate(const char *str, int *i)
{
	char	*dupl;
	int		j;

	j = 0;
	if (!str)
		return (NULL);
	if (!(dupl = (char *)malloc(sizeof(char) * (*i))))
		return (NULL);
	while (j < *i)
	{
		dupl[j] = str[j];
		j++;
	}
	dupl[j] = '\0';
	return (dupl);
}
