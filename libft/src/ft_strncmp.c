/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:44:58 by mchamma           #+#    #+#             */
/*   Updated: 2024/07/23 19:26:50 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Compares the first n bytes of str1 and str2.

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return ((unsigned char)(str1[i]) - (unsigned char)(str2[i]));
		i++;
	}
	return (0);
}

// #include<stdio.h>
// #include<string.h>

// int	main(void)
// {
// 	const char	*str1;
// 	const char	*str2;
// 	size_t		n;

// 	str1 = "test\200";
// 	str2 = "test\0";
// 	n = 6;
// 	printf("%d\n", strncmp(str1, str2, n));
// 	printf("%d\n", ft_strncmp(str1, str2, n));
// 	return (0);
// }
