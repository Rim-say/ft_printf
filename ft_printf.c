#include "ft_printf.h"

void handle_format(va_list args, char *str, int *count)
{
	if (*str == 'c')
		ft_putchar(va_arg(args, int), count);
	else if(*str == 's')
		ft_putstr(va_arg(args, char *), count);
	else if(*str == 'p')
		ft_putptr(va_arg(args, unsigned long), count);
	else if(*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if(*str == 'u')
		ft_putunsigned(va_arg(args, unsigned int), count);
	else if(*str == 'x')
		ft_puthex(va_arg(args, unsigned int), 'x', count);
	else if(*str == 'X')
		ft_puthex(va_arg(args, unsigned int), 'X', count);
	else if (*str == '%')
		ft_putchar(*str, count);
}

int ft_printf(const char *str, ...)
{
	va_list	args;
	int	count;

	count = 0;
	va_start(args, str);
	while (*str){
		if(*str == '%')
		{
			str++;
			handle_format(args, str, &count);
		}
		else
			ft_putchar(*str, &count);
		str++;
	}
	va_end(args);
	return (count);
}