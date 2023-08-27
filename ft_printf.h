/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahzakzou <ahzakzou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 03:12:24 by ahzakzou          #+#    #+#             */
/*   Updated: 2023/08/28 00:23:38 by ahzakzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

int	ft_putchar(char ch);
int	print_str(char *str);
int	print_b(long long int num, unsigned long long int num2, char *s, int base);
int	print_base2(unsigned long long int num, char *s, int base, char flag);
int	ft_printf(const char *s, ...);

#endif