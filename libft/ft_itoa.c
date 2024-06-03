/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:38:28 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/05/16 18:38:41 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_n_len(long lnb);
size_t	ft_n_sign(long lnb);

char	*ft_itoa(int n)
{
	long	lnb;	
	size_t	sign;
	size_t	len;
	char	*ptr;

	lnb = n;
	sign = ft_n_sign(lnb);
	if (sign == 1)
		lnb = -lnb;
	len = ft_n_len(lnb) + sign;
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[len--] = '\0';
	if (lnb == 0)
		ptr[len] = '0';
	while (lnb > 0)
	{
		ptr[len--] = (lnb % 10) + '0';
		lnb = lnb / 10;
	}
	if (sign == 1)
		ptr[len] = '-';
	return (ptr);
}

size_t	ft_n_sign(long lnb)
{
	size_t	sign;

	sign = 0;
	if (lnb < 0)
		sign = 1;
	return (sign);
}

size_t	ft_n_len(long lnb)
{
	size_t	len;

	len = 0;
	if (lnb == 0)
		len = 1;
	while (lnb > 0)
	{
		lnb = lnb / 10;
		len++;
	}
	return (len);
}
