/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahzakzou <ahzakzou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 03:12:24 by ahzakzou          #+#    #+#             */
/*   Updated: 2023/08/27 18:13:46 by ahzakzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF
#define LIBFT_PRINTF

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_putchar(char ch);
int	print_str(char *str);
int	print_base( long long int num, char *s, int base);
int ft_printf(const char *, ...);

#endif