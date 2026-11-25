#include "ft_printf.h"

void    ft_putnbr(int n, int *count)
{
    if (n == -2147483648)
    {
        ft_putstr("-2147483648", count);
    }
    else if (n < 0)
    {
        n = -n;
        ft_putnbr(n, count);
    }
    else if (n < 10)
    {
        ft_putchar(n + '0', count);
    }
    else{
        ft_putnbr(n / 10, count);
        ft_putchar(n % 10 + '0', count);
    }
}
