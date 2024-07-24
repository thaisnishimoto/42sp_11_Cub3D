/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_repeat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:00:34 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:07:48 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Check if there is repeated integers in the array

#include "libft.h"

int	ft_array_repeat(long int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (arr[i] == arr[j])
				return (1);
			j--;
		}
		i++;
	}
	return (0);
}
