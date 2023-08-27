/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahzakzou <ahzakzou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 03:12:01 by ahzakzou          #+#    #+#             */
/*   Updated: 2023/08/27 18:13:40 by ahzakzou         ###   ########.fr       */
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
	while (str [i])
		ft_putchar(str[i++]);
	return (i);
}

int	print_base( long long int num, char *s, int base)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		count++;
		num = -num;
	}
	if (num / base > 0)
		count += print_base(num / base, s, base);
	count += write(1, &s[num % base], 1);
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
		count += print_base(va_arg(arg, int), "0123456789", 10);
	else if (ch == 'u')
		count += print_base(va_arg(arg, unsigned int), "0123456789", 10);
	else if (ch == 'x')
		count += print_base(va_arg(arg, unsigned int), "0123456789abcdef", 16);
	else if (ch == 'p')
	{
		write(1, "0x", 2);
		count += print_base(va_arg(arg, long long int), \
		"0123456789abcdef", 16) + 2;
	}
	else if (ch == 'X')
		count += print_base(va_arg(arg, unsigned int), "0123456789ABCDEF", 16);
	else if (ch == '%')
		write(1, "%", 1);
	return (count);
}

int ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arg, s);
	while (s[i] && s[i + 1])
	{
		if (s[i] == '%')
		{
			count += ft_printf(&s[++i], arg);
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
// 	int x;
// 	int y;
// 	int xx = 200000;
// 	int yy = -200000;
// 	char *tmp = "hello this is test";
// 	x = printf("%s %p %i %d %% %% %x %x %% %c %u",tmp, &tmp, xx, yy, xx, yy, tmp[0], (unsigned int)y);
// 	// x = printf("%% %% %x %X %% %cl %unotpercent", x, y, tmp[0], (unsigned int)y);
// 	printf("\n");
// 	// y = ft_printf("%% %% %x %X %% %cl %unotpercent", x, y, tmp[0], (unsigned int)y);
// 	y = ft_printf("%s %p %i %d %% %% %x %x %% %c %u",tmp, &tmp, xx, yy, xx, yy, tmp[0], (unsigned int)y);
// 	printf("\n");
// 	printf("\n%d\n%d\n", x, y);
// }