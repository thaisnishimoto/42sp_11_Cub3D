/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:12:55 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:33:38 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Outputs the char to the given file descriptor

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include<fcntl.h>

// int	main(void)
// {
// 	int	c;
// 	int	fd;

// 	fd = open("xxxx.c", O_WRONLY | O_CREAT, 0644);
// 	if (fd < 0)
// 		return (-1);
// 	c = 'a';
// 	fd = 1;

// 	ft_putchar_fd(c, fd);

// 	close (fd);

// 	return (0);
// }
