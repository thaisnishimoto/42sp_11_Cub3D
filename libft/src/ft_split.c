/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:16:44 by mchamma           #+#    #+#             */
/*   Updated: 2024/07/22 02:21:58 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Split a string by separator

#include "libft.h"

char	**ft_destroy(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	return (0);
}

char	**ft_word_assemble(char const *s, char c, char **ret)
{
	size_t	i;
	size_t	y;
	size_t	start;
	size_t	s_len;

	s_len = ft_strlen(s);
	start = 0;
	y = 0;
	i = 0;
	while (i < s_len && s[i] != '\n')
	{
		if ((s[i] != c && s[i] != '\n' && s[i] != '\0') \
			&& (i == 0 || s[i - 1] == c))
			start = i;
		if (s[i] != c && \
			(s[i + 1] == c || s[i + 1] == '\0' || s[i + 1] == '\n'))
		{
			ret[y] = ft_substr(s, start, i - start + 1);
			if (!ret[y])
				return (ft_destroy(ret));
			y++;
		}
		i++;
	}
	return (ret);
}

int	ft_count_words(char const *s, char c)
{
	size_t	count_words;
	size_t	i;

	count_words = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i] != '\n' && s[i] != '\0') \
			&& (i == 0 || s[i - 1] == c))
			count_words++;
		i++;
	}
	return (count_words);
}

// Returns an array of str by splitting teh string using a char

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	count_words;

	count_words = ft_count_words(s, c);
	ret = (char **) ft_calloc((count_words + 1), sizeof(char *));
	if (!ret)
		return (0);
	ret = ft_word_assemble(s, c, ret);
	return (ret);
}

// #include<stdio.h>

// int	main(void)
// {
// 	char		**ret;
// 	char const	*s;
// 	char		c;
// 	int			i;

// 	s = "--1-2--3---4----5-----42";
// 	c = '-';
// 	ret = ft_split(s, c);

// 	i = 0;
// 	while (ret[i] != 0)
// 	{
// 		printf("%s\n", ret[i]);
// 		free(ret[i]);
// 		i++;
// 	}
// 	free(ret);
// 	return (0);
// }
