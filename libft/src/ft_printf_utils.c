/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:48:40 by mchamma           #+#    #+#             */
/*   Updated: 2024/03/05 12:54:58 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Outputs the char to the file descriptor standard output #1

#include "libft.h"

int	ft_pf_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

// Outputs the number decimal to the file descriptor standard output #1

int	ft_pf_putnbr(int n, char flag)
{
	int	unit;
	int	count;

	count = 1;
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		unit = (n % 10) * -1 + '0';
		n /= -10;
	}
	else
	{
		if (n >= 0 && (flag == '+' || flag == ' '))
			count += ft_pf_putchar(flag);
		unit = (n % 10) + '0';
		n /= 10;
	}
	flag = 0;
	if (n > 0)
		count += ft_pf_putnbr(n, flag);
	write(1, &unit, 1);
	return (count);
}

// Outputs the number value according to the base. And to the 
// file descriptor standard output #1

int	ft_pf_putnbrbase(size_t n, char *tab, size_t base, char flag)
{
	size_t	count;

	count = 1;
	if (n && flag == '#')
		count += ft_pf_putstr(&tab[16]);
	flag = 0;
	if (n >= base)
		count += ft_pf_putnbrbase(n / base, tab, base, flag);
	write(1, &tab[n % base], 1);
	return (count);
}

// Outputs the pointer value according to the base. And to the 
// file descriptor standard output #1

int	ft_pf_putptr(size_t address)
{
	int	count;

	count = 1;
	if (!address)
		return (ft_pf_putstr("(nil)"));
	if (address < 16)
	{
		ft_pf_putstr(&LOWER[16]);
		count += 2;
	}
	else
		count += ft_pf_putptr(address / 16);
	write(1, &LOWER[address % 16], 1);
	return (count);
}

// Outputs the str to the file descriptor standard output #1

int	ft_pf_putstr(char *s)
{
	int	count;

	if (!s)
		return (ft_pf_putstr("(null)"));
	count = 0;
	while (s[count])
	{
		write(1, &s[count], 1);
		count++;
	}
	return (count);
}
