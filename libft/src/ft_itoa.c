/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:54:43 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:28:38 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Converts the decimal to string argument

#include "libft.h"

char	*ft_strass(int n, char *ret, int count)
{
	int	start;
	int	end;

	start = 0;
	end = count - 1;
	if (n < 0)
		ret[start++] = '-';
	while (end >= start)
	{
		if (n < 0)
		{
			ret[end] = (n % 10) * -1 + '0';
			n = n / -10;
		}
		else
		{
			ret[end] = n % 10 + '0';
			n = n / 10;
		}
		end--;
	}
	ret[count] = 0;
	return (ret);
}

int	ft_nbrlen(int n)
{
	int	count;

	if (n == 0)
		return (1);
	else if (n < 0)
		count = 1;
	else
		count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

// Returns a str representing the integer

char	*ft_itoa(int n)
{
	char	*ret;
	int		count;

	count = ft_nbrlen(n);
	ret = (char *)malloc((count + 1) * sizeof(char));
	if (!ret)
		return (0);
	ret = ft_strass(n, ret, count);
	return (ret);
}

// #include<stdio.h>

// int	main(void)
// {
// 	int		n;
// 	char	*ret;

// 	n = -2147483648;

// 	ret = ft_itoa(n);
// 	printf("%s\n", ret);
// 	free(ret);
// 	return (0);
// }
