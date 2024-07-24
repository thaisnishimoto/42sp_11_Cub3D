/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:15:53 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:18:02 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Converts the string argument to a decimal

#include "libft.h"

int	ft_atoi(const char *str)
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
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

// #include<stdlib.h>
// #include<stdio.h>

// int	main(void)
// {
// 	const char	*str;

// 	str = ((void*)0);
// 	printf("Com: %d\n", atoi(str));
// 	// printf("Fun: %d\n", ft_atoi(str));
// 	return (0);
// }
