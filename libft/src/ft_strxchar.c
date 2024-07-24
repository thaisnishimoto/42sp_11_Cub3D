/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:06:45 by mchamma           #+#    #+#             */
/*   Updated: 2024/04/02 12:21:21 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Return quantity of char within a string

#include "libft.h"

int	ft_strxchar(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
