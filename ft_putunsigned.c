#include "ft_printf.h"

void ft_putunsigned(unsigned int n, int *count)
{
    if (n >= 10)
        ft_putunsigned(n / 10, count);
    ft_putchar(n % 10 + '0', count);
}
