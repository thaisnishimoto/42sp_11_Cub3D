/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:53:11 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:31:20 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Copies n characters from memory area src to dest

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (dst);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

// #include<string.h>
// #include<stdio.h>

// int	main(void)
// {
// 	char	*src;
// 	char	*dst;
// 	size_t	n;

// 	dst = ((void*)0);
// 	src = ((void*)0);
// 	n = 3;

// 	// memcpy(dst, src, n);
// 	// printf("%s\n", dst);

// 	ft_memcpy(dst, src, n);
// 	printf("%s\n", dst);

// 	return (0);
// }
