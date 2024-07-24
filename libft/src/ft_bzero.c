/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:28:02 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:18:23 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Places n zero-valued bytes in the string

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*p;

	p = str;
	i = 0;
	while (i != n)
	{
		p[i] = '\0';
		i++;
	}
}

// #include<strings.h>
// #include<stdio.h>

// int	main(void)
// {
// 	char	str1[10] = "Salve";
// 	char	str2[10] = "Salve";
// 	size_t	n;
// 	size_t	i;

// 	n = 2;
// 	bzero(str1, n);
// 	printf("%s\n", str1);
// 	i = 0;
// 	while (i < sizeof(str1))
// 	{
// 		printf("%c", str1[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	ft_bzero(str2, n);
// 	printf("%s\n", str2);
// 	i = 0;
// 	while (i < sizeof(str2))
// 	{
// 		printf("%c", str2[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	return (0);
// }
