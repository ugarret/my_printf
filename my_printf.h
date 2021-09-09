#ifndef MY_PRINTF_H
# define MY_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct
{
	int		flag_m;
	int		flag_z;
	int		flag_p;
	int		flag_s;
	int		width;
	int		precision;
	char	type;
	int		count;
}			t_parsing;

int			my_printf(const char *format, ...);
void		my_initialization(t_parsing *option);
int			my_work_arg(int i, const char *f, t_parsing *option, va_list ap);
int			my_parser(int i, const char *format, t_parsing *option, va_list ap);
int			my_prs_w(int i, const char *format, t_parsing *option, va_list ap);
int			my_prs_p(int i, const char *format, t_parsing *option, va_list ap);
char		*my_strchr(const char *str, int chr);
int			my_atoi(const char *str);
int			my_processor(t_parsing *option, va_list ap);
int			my_type_d_and_i(t_parsing *option, va_list ap, int i);
int			my_type_u(t_parsing *option, va_list ap, int i);
int			my_type_x(t_parsing *option, va_list ap, int i);
int			my_type_p(t_parsing *option, va_list ap, int i);
int			my_type_c_and_percent(t_parsing *option, va_list ap, int i);
int			my_type_s(t_parsing *option, va_list ap, int i);
void		check_flags_for_d(t_parsing *option, int x);
void		check_flags_for_u_x_p(t_parsing *option, unsigned int x);
int			my_count(int n);
int			my_count_for_u(unsigned int n);
int			my_count_for_x(unsigned int n);
int			my_count_for_p(unsigned long int n);
char		*my_itoa_for_d(int num, int len, t_parsing *option, int *i);
char		*my_itoa_for_u(unsigned int n, int len, t_parsing *option, int *i);
char		*my_itoa_for_x(unsigned int n, int len, t_parsing *option, int *i);
char		*my_it_f_p(unsigned long int n, int len, t_parsing *option, int *i);
int			my_print_space (t_parsing *option, int len, int i);
int			my_print_minus (t_parsing *option, int i);
int			my_print_zero(t_parsing *option, int len, int i);
int			my_print_number_or_word(char *number, int i);
int			my_strlen(const char *str);
char		*my_duplicate(const char *str, int *i);

#endif
