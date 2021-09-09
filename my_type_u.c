#include "my_printf.h"

int		my_type_u(t_parsing *option, va_list ap, int i)
{
	unsigned int	x;
	char			*number;
	int				len;

	x = va_arg(ap, unsigned int);
	len = my_count_for_u(x);
	check_flags_for_u_x_p(option, x);
	if (!option->flag_m && !option->flag_z)
		i = my_print_space(option, len, i);
	if (!(option->flag_p && !option->precision) || (x != 0))
	{
		if (!(number = my_itoa_for_u(x, len, option, &i)))
			return (-1);
		i = my_print_number_or_word(number, i);
	}
	if (option->flag_m)
		i = my_print_space(option, len, i);
	return (i);
}

char	*my_itoa_for_u(unsigned int n, int len, t_parsing *option, int *i)
{
	char	*str;

	if (option->flag_z || option->precision > len)
		*i = my_print_zero(option, len, *i);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

int		my_count_for_u(unsigned int n)
{
	int		count;

	count = (n) ? 0 : 1;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
