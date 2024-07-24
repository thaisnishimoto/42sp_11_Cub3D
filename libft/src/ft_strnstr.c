/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:24:48 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:48:45 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Locates the	1st occurrence of to_find in the str, restricted by len

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[0] == 0)
		return ((char *)&str[0]);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j] && (i + j) < len)
			j++;
		if (!to_find[j])
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

// #include<stdio.h>
// #include<bsd/string.h>

// // cc -Werror -Wextra -Wall ft_strnstr.c -lbsd && ./a.out && rm a.out

// int	main(void)
// {
// 	const char	*str;
// 	const char	*to_find;
// 	size_t		len;

// 	str = "aaabcabcd";
// 	to_find = "aabc";
// 	len = -1;

// 	printf("Com: %s\n", strnstr(str, to_find, len));
// 	printf("Fun: %s\n", ft_strnstr(str, to_find, len));

// 	return (0);
// }
