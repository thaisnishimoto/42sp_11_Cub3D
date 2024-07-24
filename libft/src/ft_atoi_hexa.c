/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:21:50 by mchamma           #+#    #+#             */
/*   Updated: 2023/10/05 13:24:53 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Converts the string argument to an hexadecimal

#include "libft.h"

int	ft_convert_char(char c)
{
	if (c == 'a' || c == 'A')
		return (10);
	else if (c == 'b' || c == 'B')
		return (11);
	else if (c == 'c' || c == 'C')
		return (12);
	else if (c == 'd' || c == 'D')
		return (13);
	else if (c == 'e' || c == 'E')
		return (14);
	else if (c == 'f' || c == 'F')
		return (15);
	else
		return (c - '0');
}

int	ft_atoi_hexa(const char *str)
{
	int	i;
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '0' || str[i] == 'x' || str[i] == 'X')
		i++;
	while (ft_ishexa(str[i]))
	{
		result = result * 16 + (ft_convert_char(str[i]));
		i++;
	}
	return (sign * result);
}

// #include<stdlib.h>
// #include<stdio.h>

// int	main(void)
// {
// 	const char	*str;

// 	str = "0xff00";
// 	printf("Fun: %d\n", ft_atoi_hexa(str));
// 	printf("Fun: %x\n", ft_atoi_hexa(str));
// 	return (0);
// }
