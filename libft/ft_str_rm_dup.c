/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rm_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:52:54 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/09/28 18:59:54 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_rm_dup(char *str, char c)
{
	int		i;
	int		len;
	char	buffer[1024];
	char	*ptr;

	if (str == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != c)
			buffer[len++] = str[i++];
		else if (str[i] == c)
		{
			buffer[len++] = str[i++];
			while (str[i] == c)
				i++;
		}
	}
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, buffer, len + 1);
	return (ptr);
}
