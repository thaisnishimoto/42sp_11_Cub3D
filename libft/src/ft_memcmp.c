/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:51:31 by mchamma           #+#    #+#             */
/*   Updated: 2024/07/23 19:26:25 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Compares the first n bytes of memory area str1 and str2

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)str1)[i] != ((unsigned char *)str2)[i])
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
		i++;
	}
	return (0);
}

// #include<string.h>
// #include<stdio.h>

// int	main(void)
// {
// 	const char	*str1;
// 	const char	*str2;
// 	size_t		n;

// 	str1 = "Marcio";
// 	str2 = "Marcelo";
// 	n = 1;
// 	printf("%d\n", memcmp(str1, str2, n));
// 	printf("%d\n", ft_memcmp(str1, str2, n));
// 	return (0);
// }
