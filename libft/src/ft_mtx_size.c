/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:12:43 by mchamma           #+#    #+#             */
/*   Updated: 2024/03/30 00:19:47 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Calculate the quantity of line of the matrix

#include "libft.h"

int	ft_mtx_size(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
		i++;
	return (i);
}
