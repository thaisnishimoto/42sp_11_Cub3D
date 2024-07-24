/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:04:18 by mchamma           #+#    #+#             */
/*   Updated: 2024/03/05 13:01:35 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Emulate the function printf

#include "libft.h"

int	ft_printcontrol(va_list args, char format, char flag)
{
	int		count;

	count = 0;
	if (format == 'c')
		count += ft_pf_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_pf_putstr(va_arg(args, char *));
	else if (format == 'p')
		count += ft_pf_putptr(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		count += ft_pf_putnbr(va_arg(args, int), flag);
	else if (format == 'u')
		count += ft_pf_putnbrbase(va_arg(args, unsigned int), LOWER, 10, flag);
	else if (format == 'x')
		count += ft_pf_putnbrbase(va_arg(args, unsigned int), LOWER, 16, flag);
	else if (format == 'X')
		count += ft_pf_putnbrbase(va_arg(args, unsigned int), UPPER, 16, flag);
	else if (format == '%')
		count += ft_pf_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (str[i] == '#' || str[i] == '+' || str[i] == ' ')
				i++;
			count += ft_printcontrol(args, str[i], str[i - 1]);
		}
		else
			count += ft_pf_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		count;
// 	int		a;

// 	a = 0;
// 	count = ft_printf("%#x", a);
// 	ft_printf(" -> tamanho: %d\n", count);
// 	count = printf("%#x", a);
// 	printf(" -> tamanho: %d\n", count);
// 	return (0);
// }
