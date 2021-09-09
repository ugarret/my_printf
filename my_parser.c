#include "my_printf.h"

int		my_parser(int i, const char *format, t_parsing *option, va_list ap)
{
	if (format[i] == '0' && format[i + 1] != '.')
	{
		option->flag_z = 1;
		i++;
	}
	if (format[i] == '-')
	{
		option->flag_m = 1;
		i++;
	}
	while ((format[i] == '0' && format[i + 1] != '.') || format[i] == '-')
		i++;
	if ((format[i] >= '0' && format[i] <= '9') || format[i] == '*')
		i = my_prs_w(i, format, option, ap);
	if (format[i] == '.')
		i = my_prs_p(i, format, option, ap);
	if (my_strchr("cspdiuxX%", format[i]))
	{
		option->type = format[i];
		i++;
	}
	else
		return (-1);
	return (i);
}

int		my_prs_w(int i, const char *format, t_parsing *option, va_list ap)
{
	if (format[i] == '*')
	{
		option->width = va_arg(ap, int);
		if (option->width < 0)
		{
			option->width *= -1;
			if (!option->flag_m)
			{
				option->flag_m = 1;
				if (option->flag_z)
					option->flag_z = 0;
			}
		}
		i++;
	}
	else
	{
		option->width = my_atoi(&format[i]);
		while (format[i] >= '0' && format[i] <= '9')
			i++;
	}
	return (i);
}

int		my_prs_p(int i, const char *format, t_parsing *option, va_list ap)
{
	i++;
	option->flag_p = 1;
	if (format[i] == '*')
	{
		option->precision = va_arg(ap, int);
		i++;
		option->flag_s = 1;
	}
	else
	{
		if ((option->precision = my_atoi(&format[i])) == 0)
			option->flag_s = 1;
		while (format[i] >= '0' && format[i] <= '9')
			i++;
	}
	return (i);
}

char	*my_strchr(const char *str, int chr)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)chr)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

int		my_atoi(const char *str)
{
	int				i;
	unsigned long	num;
	int				znak;

	i = 0;
	num = 0;
	znak = 1;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 13) || str[i] == '\r')
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	else if (str[i] == '-')
	{
		znak = znak * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * znak);
}
