/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:01:30 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:26:24 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Compare and return the value. The sign represent the type of comparison

#include "libft.h"

int	ft_intcmp(int a, int b, char comparison)
{
	if (comparison == '+')
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	else if (comparison == '-')
	{
		if (a < b)
			return (a);
		else
			return (b);
	}
	return (0);
}
