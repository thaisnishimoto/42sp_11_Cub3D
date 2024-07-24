/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:17:01 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:18:34 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates memory, sets allocated memory to zero and returns a pointer

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*new_str;
	size_t	i;

	if (nitems == 0 || size == 0)
		return (malloc(0));
	if ((nitems * size) / size != nitems)
		return (0);
	new_str = (void *)malloc(nitems * size);
	if (!new_str)
		return (0);
	i = 0;
	while (i < nitems * size)
	{
		((char *)new_str)[i] = 0;
		i++;
	}
	return (new_str);
}

// #include<stdio.h>

// int	main(void)
// {
// 	size_t	nitems;
// 	size_t	size;
// 	int		*arr;
// 	size_t	i;

// 	nitems = 5;
// 	size = sizeof(int);
// 	arr = ft_calloc(nitems, size);
// 	arr[0] = 100000000;
// 	i = 0;
// 	while (i < nitems)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}
// 	free(arr);
// 	return (0);
// }

// cc -Werror -Wextra -Wall -g ft_calloc.c -L. -lft && valgrind ./a.out