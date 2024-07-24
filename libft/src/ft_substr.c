/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:41:22 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:49:06 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Creates a substring from string s, lauching from start and with len elements

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	s_len;
	size_t	i;

	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	new_s = malloc((len + 1) * sizeof(char));
	if (!new_s)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		new_s[i] = s[start + i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

// #include<stdio.h>

// int	main(void)
// {
// 	char const		*s;
// 	char			*ret;
// 	unsigned int	start;
// 	size_t			len;

// 	s = "0123456789";
// 	start = 9;
// 	len = 10;

// 	ret = ft_substr(s, start, len);
// 	printf("%s\n", ret);
// 	free(ret);
// 	return (0);
// }
