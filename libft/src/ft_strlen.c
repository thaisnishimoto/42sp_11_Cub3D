/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:02:56 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:48:00 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Computes the length of the string, not including the last null character

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// #include<string.h>
// #include<stdio.h>

// int	main(void)
// {
// 	printf("Com: %lu\n", strlen("Marcio"));
// 	printf("Fun: %zu\n", ft_strlen("Marcio"));

// 	return (0);
// }
