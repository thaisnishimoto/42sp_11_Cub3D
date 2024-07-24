/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:58:06 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:43:14 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Outputs the number decimal to the given file descriptor

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	unit;

	if (n < 0)
	{
		write(fd, "-", 1);
		unit = (n % 10) * -1 + '0';
		n /= -10;
	}
	else
	{
		unit = (n % 10) + '0';
		n /= 10;
	}
	if (n > 0)
		ft_putnbr_fd(n, fd);
	write(fd, &unit, 1);
}

// int	main(void)
// {
// 	int	n;
// 	int	fd;

// 	n = -1111111111;
// 	fd = 0;
// 	ft_putnbr_fd(n, fd);
// 	return (0);
// }
