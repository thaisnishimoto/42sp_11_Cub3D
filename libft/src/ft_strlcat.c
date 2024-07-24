/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:44:09 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:47:43 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Concatenates two strings.

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_size;
	size_t	dst_size;
	size_t	i;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size <= dst_size)
		return (size + src_size);
	else
	{
		i = 0;
		while (src[i] != '\0' && i < size - dst_size - 1)
		{
			dst[dst_size + i] = src[i];
			i++;
		}
		dst[dst_size + i] = '\0';
		return (dst_size + src_size);
	}
}

// #include<stdio.h>
// #include<bsd/string.h>

// cc -Werror -Wextra -Wall ft_strlcat.c -lbsd && ./a.out && rm a.out

// int	main(void)
// {
// 	char	src[] = "marcio";
// 	char	dst1[] = "lu";
// 	char	dst2[] = "lu";
// 	size_t	size;

// 	size = 2;
// 	printf("Fun Ret: %zu\n", ft_strlcat(dst1, src, size));
// 	printf("Fun Dst: %s\n", dst1);
// 	printf("Com Ret: %zu\n", strlcat(dst2, src, size));
// 	printf("Com Dst: %s\n", dst2);
// 	return (0);
// }
