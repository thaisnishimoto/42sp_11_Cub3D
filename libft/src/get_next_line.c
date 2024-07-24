/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:30:30 by mchamma           #+#    #+#             */
/*   Updated: 2024/07/23 19:28:21 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Read and write the line of a text

#include "libft.h"

char	*ft_isolate_backup(char *ref)
{
	char	*backup;

	backup = NULL;
	if (ft_strchr(ref, '\n'))
		backup = ft_strdup(ft_strchr(ref, '\n') + 1);
	free(ref);
	return (backup);
}

char	*ft_isolate_next_line(char *ref)
{
	int		i;
	char	*line;

	i = 0;
	while (ref[i] != '\n' && ref[i] != '\0')
		i++;
	if (ref[i] == '\0' && i == 0)
		return (NULL);
	if (ref[i] == '\n')
		i++;
	line = ft_substr(ref, 0, i);
	return (line);
}

char	*ft_finding_next_line(int fd, char *step, char *ref)
{
	char	*aux;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read (fd, step, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		step[bytes_read] = '\0';
		if (ref == NULL)
			ref = ft_strdup("");
		aux = ft_strdup(ref);
		free(ref);
		ref = ft_strjoin(aux, step);
		free(aux);
		if (ft_strchr(ref, '\n'))
			break ;
	}
	return (ref);
}

char	*get_next_line(int fd)
{
	char		*step;
	static char	*ref[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	step = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!step)
		return (NULL);
	ref[fd] = ft_finding_next_line(fd, step, ref[fd]);
	free (step);
	if (ref[fd] == NULL)
		return (NULL);
	line = ft_isolate_next_line(ref[fd]);
	ref[fd] = ft_isolate_backup(ref[fd]);
	return (line);
}

// int	main(void)
// {
// 	int		fd_1;
// 	int		fd_2;
// 	char	*line;

// 	printf("BUFFER_SIZE: %d\n\n", BUFFER_SIZE);

// 	fd_1 = open ("loren.md", O_RDONLY);
// 	printf("%d\n\n", fd_1);

// 	fd_2 = open ("mussum.md", O_RDONLY);
// 	printf("%d\n\n", fd_2);

// 	line = get_next_line(fd_1);
// 	printf("Line 1: %s\n", line);
// 	free(line);

// 	line = get_next_line(fd_2);
// 	printf("Line 2: %s\n", line);
// 	free(line);

// 	line = get_next_line(fd_1);
// 	printf("Line 3: %s\n", line);
// 	free(line);

// 	line = get_next_line(fd_2);
// 	printf("Line 4: %s\n", line);
// 	free(line);

// 	line = get_next_line(fd_1);
// 	printf("Line 5: %s\n", line);
// 	free(line);

// 	line = get_next_line(fd_2);
// 	printf("Line 6: %s\n", line);
// 	free(line);

// 	close(fd_1);
// 	close(fd_2);
// 	return (0);
// }

// cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=42
// main.c -I./ -L./ -lft && ./a.out
