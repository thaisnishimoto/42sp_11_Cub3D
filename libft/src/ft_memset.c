/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:27:37 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:31:57 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Copies the char c to the first n char of the string str

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		((char *)str)[i] = c;
		i++;
		n--;
	}
	return (str);
}

// #include<string.h>
// #include<stdio.h>

// int	main(void)
// {
// 	char	str1[10] = "Marcio";
// 	char	str2[10] = "Marcio";
// 	size_t	c;
// 	size_t	n;

// 	c = 'x';
// 	n = 10;
// 	printf("Com1: %s\n", str1);
// 	memset(str1, c, n);
// 	printf("Com2: %s\n", str1);
// 	printf("Fun1: %s\n", str2);
// 	ft_memset(str2, c, n);
// 	printf("Fun2: %s\n", str2);
// 	return (0);
// }
