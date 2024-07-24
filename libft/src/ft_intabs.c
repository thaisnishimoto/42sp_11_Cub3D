/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:56:34 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:19:44 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Return the absolute value of integer

#include "libft.h"

int	ft_intabs(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	else
		return (nbr);
}
