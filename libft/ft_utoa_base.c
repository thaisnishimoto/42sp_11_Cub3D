/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:38:28 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/06/23 20:21:02 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_base(char *base);
static char		*ft_reverse_str(char *str);

char	*ft_utoa_base(unsigned long lnb, char *base)
{
	size_t	blen;
	int		i;
	char	buffer[100];
	char	*num;

	blen = check_base(base);
	if (blen < 2)
		return (NULL);
	i = 0;
	if (lnb == 0)
		buffer[i++] = '0';
	while (lnb > 0)
	{
		buffer[i] = base[lnb % blen];
		lnb = lnb / blen;
		i++;
	}
	buffer[i] = '\0';
	num = ft_reverse_str(buffer);
	return (num);
}

static char	*ft_reverse_str(char *str)
{
	int		len;
	int		i;
	char	*str_rev;

	len = ft_strlen(str);
	str_rev = malloc((len + 1) * sizeof(char));
	if (str_rev == NULL)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		str_rev[--len] = str[i++];
	}
	str_rev[i] = '\0';
	return (str_rev);
}

static size_t	check_base(char *base)
{
	size_t	blen;
	int		i;
	int		j;

	blen = ft_strlen(base);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[i] != base[j] && base[j])
			j++;
		if (base[i] == base[j])
			return (0);
		i++;
	}
	return (blen);
}
