/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:36:43 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:48:51 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Searches for the last occurrence of the char c in the string str

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}

// #include<stdio.h>
// #include<string.h>

// int	main(void)
// {
// 	const char	*str;
// 	int			c;

// 	str = "Banana";
// 	c = 'n';

// 	printf("%s\n", strrchr(str, c));
// 	printf("%s\n", ft_strrchr(str, c));

// 	return (0);
// }
