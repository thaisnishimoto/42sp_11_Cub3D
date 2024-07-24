/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:03:26 by mchamma           #+#    #+#             */
/*   Updated: 2024/04/05 17:11:50 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Sort strings in the matrix, using the bubble method

#include "libft.h"

void	ft_mtx_sort(char **key)
{
	int		i;
	int		j;

	i = 0;
	while (key[i])
	{
		j = 0;
		while (key[j + 1])
		{
			if (ft_strcmp(key[j], key[j + 1]) > 0)
				ft_swap_str(&key[j], &key[j + 1]);
			j++;
		}
		i++;
	}
}
