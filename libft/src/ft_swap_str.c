/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:31:15 by mchamma           #+#    #+#             */
/*   Updated: 2024/04/05 12:32:12 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Swap the value of integer a and b

#include "libft.h"

void	ft_swap_str(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}
