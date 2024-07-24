/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:22:29 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:27:31 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Checks if the passed char is printable

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
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
// 		if ((isprint(i) != 0) != (ft_isprint(i) != 0))
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
