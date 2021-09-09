#include "my_printf.h"

int		my_type_d_and_i(t_parsing *option, va_list ap, int i)
{
	int		x;
	char	*number;
	int		len;

	x = va_arg(ap, int);
	len = my_count(x);
	check_flags_for_d(option, x);
	if (!option->flag_m && !option->flag_z)
	{
		if (x < 0)
			option->width--;
		i = my_print_space(option, len, i);
	}
	if (!(option->flag_p && !option->precision) || (x != 0))
	{
		if (!(number = my_itoa_for_d(x, len, option, &i)))
			return (-1);
		i = my_print_number_or_word(number, i);
	}
	if (option->flag_m)
		i = my_print_space(option, len, i);
	return (i);
}

char	*my_itoa_for_d(int num, int len, t_parsing *option, int *i)
{
	char	*str;

	if (num < 0)
		*i = my_print_minus(option, *i);
	if (option->flag_z || option->precision > len)
		*i = my_print_zero(option, len, *i);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		if (num == -2147483648)
		{
			str[--len] = '8';
			num /= 10;
		}
		num *= -1;
	}
	while (len > 0)
	{
		str[--len] = num % 10 + 48;
		num = num / 10;
	}
	return (str);
}

int		my_count(int n)
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

void	check_flags_for_d(t_parsing *option, int x)
{
	if (option->precision > 0 || (option->flag_s && !option->precision))
		option->flag_z = 0;
	if (option->flag_p && !option->flag_s && !option->precision && x != 0)
		option->width = 0;
	else if (option->flag_p && option->flag_s && !option->precision && x != 0)
		option->width--;
}
