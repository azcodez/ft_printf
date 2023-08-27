/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahzakzou <ahzakzou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 03:12:01 by ahzakzou          #+#    #+#             */
/*   Updated: 2023/08/28 00:23:30 by ahzakzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char ch)
{
	write(1, &ch, 1);
	return (1);
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	print_b(long long int tmp, unsigned long long int tmp2, char *s, int base)
{
	int	count;

	count = 0;
	if (base == 17)
	{
		base = 16;
		if (tmp2 / base > 0) 
			count += print_b(0, tmp2 / base, s, base + 1);
		count += write(1, &s[tmp2 % base], 1);
	}
	else
	{
		if (tmp < 0)
		{
			count += write(1, "-", 1);
			tmp = -tmp;
		}
		if (tmp / base > 0)
			count += print_b(tmp / base, 0, s, base);
		count += write(1, &s[tmp % base], 1);
	}
	return (count);
}

int	print_format(char ch, va_list arg)
{
	int	count;

	count = 0;
	if (ch == 'c')
		count += ft_putchar((va_arg(arg, int)));
	if (ch == 's')
		count += print_str(va_arg(arg, char *));
	else if (ch == 'd' || ch == 'i')
		count += print_b(va_arg(arg, int), 0, "0123456789", 10);
	else if (ch == 'u')
		count += print_b(va_arg(arg, unsigned int), 0, "0123456789", 10);
	else if (ch == 'x')
		count += print_b(va_arg(arg, unsigned int), 0, "0123456789abcdef", 16);
	else if (ch == 'X')
		count += print_b(va_arg(arg, unsigned int), 0, "0123456789ABCDEF", 16);
	else if (ch == 'p')
	{
		write(1, "0x", 2);
		count += print_b(0, va_arg(arg, long long), \
		"0123456789abcdef", 17) + 2;
	}
	else if (ch == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			count += print_format(s[++i], arg);
			i++;
		}
		else
			count += ft_putchar(s[i++]);
	}
	va_end(arg);
	return (count);
}
// int main()
// {
// 	int	x = printf(" %p ", -1);
// 	printf("\n");
// 	int	y = ft_printf(" %p ", -1);

// 	printf("\n%d\n%d\n", x, y);
// }