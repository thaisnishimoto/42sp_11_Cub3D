/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:00:15 by mchamma           #+#    #+#             */
/*   Updated: 2024/04/05 12:29:40 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Swap the value of integer a and b

#include "libft.h"

void	ft_swap_int(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}
