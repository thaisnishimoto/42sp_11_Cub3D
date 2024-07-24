/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:34:00 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:49:18 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Converts a given letter to uppercase

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

// #include<stdio.h>
// #include<ctype.h>

// int	main(void)
// {
// 	int	c;

// 	c = 'z';
// 	printf("%c\n", toupper(c));

// 	c = 'z';
// 	printf("%c\n", ft_toupper(c));

// 	return (0);
// }
