/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:11:48 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/04 14:52:02 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(va_list args)
{
	int	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(va_list args)
{
	char	*str;
	int		len;

	len = 0;
	str = va_arg(args, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[len])
		write(1, &str[len++], 1);
	return (len);
}

int	ft_print_ptr(va_list args)
{
	unsigned long	num;
	char			*base;
	int				len;
	char			*address;

	len = 0;
	base = "0123456789abcdef";
	num = va_arg(args, unsigned long);
	if (num == 0)
	{
		len = 5;
		write(1, "(nil)", len);
		return (len);
	}
	write(1, "0x", 2);
	address = ft_utoa_base(num, base);
	while (address[len])
		write(1, &address[len++], 1);
	free (address);
	return (len + 2);
}

int	ft_print_nbr(va_list args, const char format, char *flag_buffer)
{
	char	*num;
	int		len;
	int		i;
	int		nbr;

	len = 0;
	i = 0;
	num = NULL;
	nbr = va_arg(args, int);
	if (format == 'd' || format == 'i')
	{
		if (flag_buffer && nbr >= 0)
		{
			while (flag_buffer[len])
				write(1, &flag_buffer[len++], 1);
		}
		num = ft_itoa(nbr);
	}
	else if (format == 'u')
		num = ft_utoa(nbr);
	while (num[i])
		write(1, &num[i++], 1);
	free(num);
	len += i;
	return (len);
}

int	ft_printnbr_base16(va_list args, char *base, char *flag_buffer)
{
	char			*num;
	unsigned int	nbr;
	int				len;
	int				i;

	nbr = va_arg(args, int);
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	len = 0;
	if (flag_buffer)
	{
		while (flag_buffer[len])
			write(1, &flag_buffer[len++], 1);
	}
	i = 0;
	num = ft_utoa_base(nbr, base);
	while (num[i])
		write(1, &num[i++], 1);
	free (num);
	len += i;
	return (len);
}
