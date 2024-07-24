/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:57:24 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:26:54 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Return the sign of integer

#include "libft.h"

int	ft_intsign(int nbr)
{
	if (nbr < 0)
		return (-1);
	else
		return (1);
}
