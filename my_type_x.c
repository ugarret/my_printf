#include "my_printf.h"

int		my_type_x(t_parsing *option, va_list ap, int i)
{
	unsigned int	x;
	char			*number;
	int				len;

	x = va_arg(ap, unsigned int);
	len = my_count_for_x(x);
	check_flags_for_u_x_p(option, x);
	if (!option->flag_m && !option->flag_z)
		i = my_print_space(option, len, i);
	if (!(option->flag_p && !option->precision) || (x != 0))
	{
		if (!(number = my_itoa_for_x(x, len, option, &i)))
			return (-1);
		i = my_print_number_or_word(number, i);
	}
	if (option->flag_m)
		i = my_print_space(option, len, i);
	return (i);
}

char	*my_itoa_for_x(unsigned int n, int len, t_parsing *option, int *i)
{
	char			*str;

	if (option->flag_z || option->precision > len)
		*i = my_print_zero(option, len, *i);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = n % 16;
		if (str[len - 1] > 9 && option->type == 'x')
			str[len - 1] += ('a' - 10);
		else if (str[len - 1] > 9 && option->type == 'X')
			str[len - 1] += ('A' - 10);
		else
			str[len - 1] += '0';
		n = n / 16;
		len--;
	}
	return (str);
}

int		my_count_for_x(unsigned int n)
{
	int				count;

	count = (n) ? 0 : 1;
	while (n != 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

void	check_flags_for_u_x_p(t_parsing *option, unsigned int x)
{
	if (option->precision > 0 || (option->flag_s && !option->precision))
		option->flag_z = 0;
	if (option->flag_p && !option->flag_s && !option->precision && x != 0)
		option->width = 0;
	else if (option->flag_p && option->flag_s && !option->precision && x != 0)
		option->width--;
}
