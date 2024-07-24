/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:45:22 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:47:36 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns a new str, result of the concatenation of ’s1’ and ’s2’

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		s1len;
	int		s2len;
	int		i;
	int		j;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ret = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = 0;
	while (s1[i] != 0)
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = 0;
	return (ret);
}

// #include<stdio.h>

// int	main(void)
// {
// 	char const	*s1;
// 	char const	*s2;
// 	char		*ret;

// 	s1 = "ABCDE";
// 	s2 = "FGHIJ";

// 	ret = ft_strjoin(s1, s2);
// 	printf("%s", ret);
// 	free(ret);
// 	return (0);
// }
