/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:31:16 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:45:00 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Outputs the str to the given file descriptor

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

// int	main(void)
// {
// 	char	*s;
// 	int		fd;

// 	s = "\nend!";
// 	fd = 1;
// 	ft_putstr_fd(s, fd);
// 	return (0);
// }
