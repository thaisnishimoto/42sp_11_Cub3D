/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:20:31 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:47:22 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Duplicates a string

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*new_str;
	int		i;

	new_str = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!new_str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>

// int	main(void)
// {
// 	const char	*str;
// 	char		*ret;

// 	str = "Hello, World!";
// 	ret = strdup(str);
// 	printf("%s\n", ret);
// 	free(ret);

// 	str = "Hello, World!";
// 	ret = ft_strdup(str);
// 	printf("%s\n", ret);
// 	free(ret);

// 	return (0);
// }
