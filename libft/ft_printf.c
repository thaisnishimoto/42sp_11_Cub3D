/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:23:34 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/09/28 19:01:42 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_traverse_format_str(const char *str, va_list args);
static int	ft_print_format(const char *format, va_list args, char *flag_buff);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	if (str == NULL)
		return (-1);
	len = 0;
	va_start(args, str);
	len += ft_traverse_format_str(str, args);
	va_end(args);
	return (len);
}

static int	ft_traverse_format_str(const char *str, va_list args)
{
	int		i;
	int		len;
	char	*flag_buffer;

	i = 0;
	len = 0;
	flag_buffer = NULL;
	while (str[i])
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			len++;
		}
		else if (str[i++] == '%')
		{
			if (ft_check_flags(&str[i]) == 1)
				flag_buffer = ft_get_flag(&str[i++]);
			len += ft_print_format(&str[i], args, flag_buffer);
			if (flag_buffer)
				free (flag_buffer);
		}
		i++;
	}
	return (len);
}

static int	ft_print_format(const char *format, va_list args, char *flag_buff)
{
	int	len;

	len = 0;
	if (*format == 'c')
		len += ft_print_char(args);
	else if (*format == 's')
		len += ft_print_str(args);
	else if (*format == 'p')
		len += ft_print_ptr(args);
	else if (*format == 'd' || *format == 'i' || *format == 'u')
		len += ft_print_nbr(args, *format, flag_buff);
	else if (*format == 'x')
		len += ft_printnbr_base16(args, LOW_HEXBASE, flag_buff);
	else if (*format == 'X')
		len += ft_printnbr_base16(args, UPP_HEXBASE, flag_buff);
	else if (*format == '%')
	{
		write(1, "%", 1);
		len++;
	}
	return (len);
}

//int main(void)
//{
//	int     num;
//	int     result1;
//	int     expected1;
//	
//	num = 0;
//	printf("*Expected\n");
//	expected1 = printf("%u %x", num, num);
//	printf("\n");
//	printf("*Result ft_printf\n");
//	result1 = ft_printf("%u %x", num, num);
//	printf("\n");
//	return (0);
//}
