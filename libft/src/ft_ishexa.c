/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:57:41 by mchamma           #+#    #+#             */
/*   Updated: 2023/10/05 13:25:01 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Checks if the informed char is a hexadecimal digit

#include "libft.h"

int	ft_ishexa(int c)
{
	return (ft_isdigit (c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}

// #include<stdio.h>
// #include<ctype.h>

// int	main(void)
// {
// 	int	i;

// 	i = 46;
// 	while (i < 176)
// 	{
// 		if ((ft_ishexa(i) != 0))
// 			printf("%c - OK\n", i);
// 		else
// 			printf("%c - NOK\n", i);
// 		i++;
// 	}
// 	return (0);
// }
