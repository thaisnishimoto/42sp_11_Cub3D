/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:58:56 by mchamma           #+#    #+#             */
/*   Updated: 2024/04/05 17:08:47 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Insert a substr in string
// pos: position in string that substr will be placed
// clear: space in string that will be removed, starting in the pos

#include "libft.h"

char	*ft_substr_insert(char *str, int pos, int clear, char *sub)
{
	char	*left;
	char	*right;
	char	*result1;
	char	*result2;

	left = ft_substr(str, 0, pos);
	right = ft_substr(str, pos + clear, ft_strlen(str) - pos - clear);
	result1 = ft_strjoin(left, sub);
	result2 = ft_strjoin(result1, right);
	free(result1);
	free (left);
	free(right);
	return (result2);
}
