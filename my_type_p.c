#include "my_printf.h"

int		my_type_p(t_parsing *option, va_list ap, int i)
{
	unsigned long int	x;
	char				*number;
	int					len;

	x = va_arg(ap, unsigned long int);
	len = my_count_for_p(x);
	option->width -= 2;
	check_flags_for_u_x_p(option, x);
	if (option->flag_p && !option->precision && x == 0)
		len = 0;
	if (!option->flag_m)
		i = my_print_space(option, len, i);
	if (!(number = my_it_f_p(x, len, option, &i)))
		return (-1);
	i = my_print_number_or_word(number, i);
	if (option->flag_m)
		i = my_print_space(option, len, i);
	return (i);
}

char	*my_it_f_p(unsigned long int n, int len, t_parsing *option, int *i)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	write(1, "0x", 2);
	*i += 2;
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = n % 16;
		if (str[len - 1] > 9 && option->type == 'p')
			str[len - 1] += ('a' - 10);
		else
			str[len - 1] += '0';
		n = n / 16;
		len--;
	}
	return (str);
}

int		my_count_for_p(unsigned long int n)
{
	int			count;

	count = (n) ? 0 : 1;
	while (n != 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}
