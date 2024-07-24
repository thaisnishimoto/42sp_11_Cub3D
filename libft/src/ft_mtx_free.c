/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:17:35 by mchamma           #+#    #+#             */
/*   Updated: 2024/03/14 09:10:35 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Free the memory allocation of a matrix (two dimension array)

#include "libft.h"

void	ft_mtx_free(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
	{
		free (mtx[i]);
		i++;
	}
	free (mtx);
}
