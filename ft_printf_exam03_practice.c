/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_exam03_practice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:45:45 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/30 18:34:28 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int ft_putstr(char *s)
{
    int i = 0;
    int x = 0;
    while (s[i])
        x += write(1, &s[i++], 1);
    return (x);
}

int ft_putnbr(int n)
{
    long long nb;
    int res = 0;
    nb = n;
    if (nb < 0)
    {
        res += ft_putchar('-');
        nb *= -1;
    }
    if (nb > 9)
    {
        res += ft_putnbr(nb / 10);
        res += ft_putnbr(nb % 10);
    }else
        res += ft_putchar(nb + 48);
    return (res);
}

unsigned int ft_puthexa(unsigned int n)
{
    int res = 0;
    char s [] = "0123456789abcdef";
    if (n < 0)
        n *= -1;
    if (n > 15)
    {
        res += ft_puthexa(n / 16);
        res += ft_puthexa(n % 16);
    }else
        res += ft_putchar(s[n]);
    return (res);
}

int ft_printf(const char *s,...)
{
    va_list p;
    int i;
    int res;

    va_start(p, s);
    i = 0;
    while (s[i])
    {
        if(s[i] == '%')
        {
            i++;
            if (s[i] == 'd')
                res += ft_putnbr(va_arg(p, int));
            else if (s[i] == 's')
                res += ft_putstr(va_arg(p, char *));
            else if (s[i] == 'x')
                res += ft_puthexa(va_arg(p, unsigned int));
        }
        else
            res += ft_putchar(s[i]);
        i++;
    }
    va_end(p);
    return (res);
}
int main ()
{
    printf("\n-------integer-------\n");
    ft_printf("dyali %d\n", 1337);
    printf("dyalhom %d\n", 1337);
    printf("\n-------string-------\n");
    ft_printf("dyali %s\n", "salam cv");
    printf("dyalhom %s\n", "salam cv");
    printf("\n-------hexa-------\n");
    ft_printf("dyali %x\n", 17);
    printf("dyalhom %x\n", 17);
}
