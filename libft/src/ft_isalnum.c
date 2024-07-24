/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:22:29 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:27:06 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Checks if the char is alphanumeric

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'));
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
// 		if ((isalnum(i) != 0) != (ft_isalnum(i) != 0))
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
