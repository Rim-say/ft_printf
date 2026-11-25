#include "ft_printf.h"

void ft_puthexptr(unsigned long n, int *count){
    char lowercase[17] = "0123456789abcdef";
    if (n >= 16)
        ft_puthexptr(n / 16, count);
    ft_putchar(lowercase[n % 16], count);
}

void ft_putptr(void *ptr, int *count)
{
    if(!ptr)
    {
        ft_putstr("(nil)", count);
        return ;
    }
    ft_putstr("0x", count);
    unsigned long address = (unsigned long)ptr;
    ft_puthexptr(address, count);
}