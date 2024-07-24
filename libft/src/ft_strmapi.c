/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:19:37 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:48:06 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Applies the function ’f’ to each character of the str, 
// and passing its index as first argument to create a new str

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_s;

	new_s = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new_s)
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	new_s[i] = 0;
	return (new_s);
}

// #include<stdio.h>

// char	add0ne(unsigned int i, char c)
// {
// 	return (i + c);
// }

// int	main(void)
// {
// 	char const	*s;
// 	char		*new_s;

// 	s = "1234";
// 	new_s = ft_strmapi(s, &add0ne);
// 	printf("%s\n", new_s);
// 	free(new_s);
// 	return (0);
// }
