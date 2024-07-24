/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:25:02 by mchamma           #+#    #+#             */
/*   Updated: 2024/07/23 11:31:15 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	hash_elem_ext(char *line, int *arr)
{
	if (is_empty_line(line) && arr[6] != 0)
		return (9);
	else if (!is_empty_line(line) && arr[9] != 0)
		return (10);
	else
		return (11);
}

int	hash_elem(char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		return (0);
	else if (!ft_strncmp(line, "SO", 2))
		return (1);
	else if (!ft_strncmp(line, "EA", 2))
		return (2);
	else if (!ft_strncmp(line, "WE", 2))
		return (3);
	else if (!ft_strncmp(line, "F", 1))
		return (4);
	else if (!ft_strncmp(line, "C", 1))
		return (5);
	else if (is_empty_line(line))
		return (7);
	else if (ft_strchr("01NSEW", line[0]))
		return (6);
	else
		return (8);
}

void	count_file_elem_ext(char *line, int *arr)
{
	char	*new_line;

	replace_char(line, '\t', ' ');
	new_line = ft_strtrim(line, " ");
	arr[hash_elem(new_line)]++;
	arr[hash_elem_ext(new_line, arr)]++;
	free(new_line);
}

int	*count_file_elem(char *file_add)
{
	int		fd;
	char	*line;
	int		*arr;

	fd = open(file_add, O_RDONLY);
	if (fd < 0)
		error_file(3);
	arr = ft_calloc(20, sizeof(int));
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count_file_elem_ext(line, arr);
		free(line);
	}
	close(fd);
	return (arr);
}

int	validate_file_count(char *file_add)
{
	int		*arr;
	int		error_id;

	arr = count_file_elem(file_add);
	error_id = 42;
	if (arr[0] != 1 || arr[1] != 1 || arr[2] != 1 || arr[3] != 1
		|| arr[4] != 1 || arr[5] != 1)
		error_id = 4;
	else if (arr[6] < 3)
		error_id = 5;
	else if (arr[8] != 0)
		error_id = 6;
	else if (arr[10] > 0)
		error_id = 7;
	free(arr);
	return (error_id);
}
