
#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
int ft_printf(const char *, ...);
void ft_putchar(char c, int *count);
void ft_putstr(char *s, int *count);
void ft_putnbr(int n, int *count);
void ft_putunsigned(unsigned int n, int *count);
void ft_puthex(unsigned int n, char format, int *count);
void ft_putptr(void *ptr, int *count);
#endif