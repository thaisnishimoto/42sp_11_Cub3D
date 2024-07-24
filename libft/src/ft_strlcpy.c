/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:19:21 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:47:51 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Copies up to -1 char from the NULL-terminated src and gives the size of src

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// #include<stdio.h>
// #include<bsd/string.h>
// #include<string.h>

// cc -Werror -Wextra -Wall ft_strlcpy.c -lbsd && ./a.out && rm a.out

// int	main(void)
// {
// 	// char	src[] = "marcio";
// 	// char 	dst1[] = "luciaasjjahsjdhkhaksd";
// 	// char 	dst2[] = "luciaasjjahsjdhkhaksd";

// 	char 	*src = "";
// 	char 	dst1[] = "AAAAAAAAAAA";
// 	char 	dst2[] = "AAAAAAAAAAA";
// 	size_t	n;

// 	n = 42;
// 	printf("Com Ret: %zu\n", strlcpy(dst2, src, n));
// 	printf("Com Dst: %s\n", dst2);
// 	n = 42;
// 	printf("Fun Ret: %zu\n", ft_strlcpy(dst1, src, n));
// 	printf("Fun Dst: %s\n", dst1);
// 	return (0);
// }
