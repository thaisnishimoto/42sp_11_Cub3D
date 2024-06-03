/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:38:28 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/06/23 19:23:31 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_n_len(unsigned long lnb);

char	*ft_utoa(unsigned int n)
{
	unsigned long	lnb;	
	size_t			len;
	char			*num_chars;

	lnb = n;
	len = ft_n_len(lnb);
	num_chars = malloc((len + 1) * sizeof(char));
	if (num_chars == NULL)
		return (NULL);
	num_chars[len--] = '\0';
	if (lnb == 0)
		num_chars[len] = '0';
	while (lnb > 0)
	{
		num_chars[len--] = (lnb % 10) + '0';
		lnb = lnb / 10;
	}
	return (num_chars);
}

static size_t	ft_n_len(unsigned long lnb)
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
