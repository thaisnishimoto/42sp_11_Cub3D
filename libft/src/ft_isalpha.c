/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:22:29 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:27:09 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Checks if the passed char is alphabetic

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

// #include<stdio.h>
// #include<ctype.h>

// int	main(void)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i <= 255)
// 	{
// 		if ((isalpha(i) != 0) != (ft_isalpha(i) != 0))
// 		{
// 			printf("%d - Nok\n", i);
// 			j++;
// 		}
// 		else
// 			printf("%d - Ok\n", i);
// 		i++;
// 	}
// 	if (j > 0)
// 		printf("Error\n");
// 	else
// 		printf("No Error\n");
// 	return (0);
// }
