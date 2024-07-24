/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:48:11 by mchamma           #+#    #+#             */
/*   Updated: 2024/03/13 15:58:07 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Searches for the 1st occurrence of the char c in the 1st n bytes of the str

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)str)[i] == (unsigned char)c)
			return ((void *)&((unsigned char *)str)[i]);
		i++;
	}
	return (0);
}

// #include<string.h>
// #include<stdio.h>

// int	main(void)
// {
// 	// const void	*str;
// 	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
// 	char		*ret;
// 	int			c;
// 	size_t		n;

// 	// str = "Banana";
// 	c = -1;
// 	n = 7;

// 	ret = memchr(tab, c, n);
// 	printf("%p\n", ret);

// 	ret = ft_memchr(tab, c, n);
// 	printf("%p\n", ret);

// 	return (0);
// }
