/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:40:55 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:47:27 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Applies the function ’f’ on each character of the str

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include<stdio.h>

// void	iter(unsigned int i, char *s)
// {
// 	*s += i;
// }

// int	main(void)
// {
// 	char 	s[] = "0000000000";

// 	ft_striteri(s, &iter);
// 	printf("%s\n", s);
// 	return (0);
// }
