/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:15:24 by mchamma           #+#    #+#             */
/*   Updated: 2024/07/22 02:22:45 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Replace the old substr inside the str for the new substr

#include "libft.h"

char	*ft_substr_replace(char *str, char *old, char *new)
{
	int		i;
	char	*new_str;
	char	*temp;

	new_str = ft_strdup(str);
	i = 0;
	while (new_str[i])
	{
		if (ft_strnstr(&new_str[i], old, ft_strlen(new_str)) == &new_str[i])
		{
			temp = ft_substr_insert(new_str, i, ft_strlen(old), new);
			free(new_str);
			new_str = ft_strdup(temp);
			free(temp);
		}
		i++;
	}
	return (new_str);
}

// #include<stdio.h>

// int	main(void)
// {
// 	char	str[] = "Carolina - Hello Carolina";
// 	char	oldSubstr[] = "Carolina";
// 	char	newSubstr[] = "Be";
// 	char	*str2;

// 	printf("%zu - %s\n", ft_strlen(str), str);
// 	str2 = ft_substr_replace(str, oldSubstr, newSubstr);
// 	printf("%zu - %s\n", ft_strlen(str2), str2);
// 	free(str2);
// 	return (0);
// }