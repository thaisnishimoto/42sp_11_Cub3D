/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:17:29 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:47:15 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Reproduce the behavior of the function strcmp.

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2)
		i++;
	return (s1[i] - s2[i]);
}

// #include<stdio.h>
// #include<string.h>

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;

// 	s1 = "Marcao";
// 	s2 = "Marcbo";
// 	printf("%i\n", strcmp(s1, s2));
// 	printf("%i\n", ft_strcmp(s1, s2));
// 	return (0);
// }
