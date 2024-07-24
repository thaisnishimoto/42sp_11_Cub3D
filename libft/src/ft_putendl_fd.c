/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:49:14 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:38:04 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Outputs the str to the given file descriptor, followed by a newline

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	char	*s;
// 	int		fd;

// 	s = "Vai Corinthians!!!";
// 	fd = 1;
// 	ft_putendl_fd(s, fd);
// 	return (0);
// }
