/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:24:40 by mchamma           #+#    #+#             */
/*   Updated: 2024/07/25 11:32:45 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	load_map(char **file, char *line)
{
	int	i;

	i = 6;
	while (file[i])
		i++;
	file[i] = ft_strdup(line);
	return ;
}

void	load_surf(char **file, char **mtx)
{
	int	i;

	i = 0;
	while (i <= 5)
	{
		if (mtx[1] && hash_elem(mtx[0]) == i)
			file[i] = ft_strdup(mtx[1]);
		i++;
	}
}

void	load_file_ext(char *line, char **file)
{
	char	*new_line1;
	char	*new_line2;
	char	**mtx;

	new_line1 = ft_substr_replace(line, "\t", "    ");
	replace_char(new_line1, '\n', '\0');
	new_line2 = ft_strtrim(new_line1, " ");
	mtx = ft_split(new_line2, ' ');
	if (hash_elem(new_line2) >= 0 && hash_elem(new_line2) <= 5)
		load_surf(file, mtx);
	else if (hash_elem(new_line2) == 6)
		load_map(file, new_line1);
	ft_mtx_free(mtx);
	free(new_line2);
	free(new_line1);
}

int	file_rows(char *file_add)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file_add, O_RDONLY);
	if (fd < 0)
		error_file(3);
	count = 0;
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (!is_empty_line(line))
			count++;
		free(line);
	}
	close(fd);
	return (count);
}

char	**load_file(char *file_add)
{
	int		fd;
	char	*line;
	char	**file;

	fd = open(file_add, O_RDONLY);
	if (fd < 0)
		error_file(3);
	file = ft_calloc(file_rows(file_add) + 1, sizeof(char *));
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		load_file_ext(line, file);
		free(line);
	}
	close(fd);
	return (file);
}
