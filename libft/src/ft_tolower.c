/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:35:28 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:49:15 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Converts a given letter to lowercase

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

// #include<stdio.h>
// #include<ctype.h>

// int	main(void)
// {
// 	int	c;

// 	c = 'A';
// 	printf("%c\n",tolower(c));

// 	c = 'A';
// 	printf("%c\n",ft_tolower(c));

// 	return (0);
// }
