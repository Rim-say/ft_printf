#include "ft_printf.h"

void ft_puthex(unsigned int n, char format, int *count){
    char lowercase[17] = "0123456789abcdef";
    char uppercase[17] = "0123456789ABCDEF";
    if (n >= 16)
        ft_puthex(n / 16, format, count);
    if (format == 'x')
        ft_putchar(lowercase[n % 16], count);
    else if (format == 'X')
        ft_putchar(uppercase[n % 16], count);
}
