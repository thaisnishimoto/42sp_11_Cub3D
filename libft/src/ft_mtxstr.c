/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 00:18:40 by mchamma           #+#    #+#             */
/*   Updated: 2024/04/02 12:22:19 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Convert matrix data in a string

#include "libft.h"

char	*ft_mtxstr(char **mtx)
{
	char	*str1;
	char	*str2;
	int		i;

	str1 = ft_calloc(1, sizeof(char));
	i = 0;
	while (mtx[i])
	{
		str2 = ft_strdup(str1);
		free (str1);
		str1 = ft_strjoin(str2, mtx[i]);
		free(str2);
		i++;
	}
	return (str1);
}
