/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_3_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:25:17 by mchamma           #+#    #+#             */
/*   Updated: 2024/07/25 12:53:57 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	validate_map_content(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr("01NSEW ", line[i]))
			return (1);
		i++;
	}
	return (0);
}

int	validate_color_content(char *line)
{
	char	**mtx_color;
	int		check;
	int		i;

	if (!line)
		return (0);
	check = 1;
	mtx_color = ft_split(line, ',');
	if (ft_mtx_size(mtx_color) != 3)
		check = 0;
	else
	{
		i = 0;
		while (i < 3)
		{
			if (!ft_isinteger(mtx_color[i]) || !(ft_atoi(mtx_color[i]) >= 0
					&& ft_atoi(mtx_color[i]) <= 255))
				check = 0;
			i++;
		}
	}
	ft_mtx_free(mtx_color);
	return (check);
}

int	validate_texture_content(char *line)
{
	size_t			file_len;
	mlx_texture_t	*tex;
	size_t			ext_len;
	int				check;

	check = 1;
	file_len = ft_strlen(line);
	ext_len = ft_strlen(".png");
	tex = mlx_load_png(line);
	if (file_len <= ext_len || ft_strcmp(&line[file_len - 4], ".png")
		|| !tex)
		check = 0;
	if (tex)
		mlx_delete_texture(tex);
	return (check);
}

void	validate_file_content_ext(char **file, int *arr)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (i <= 3)
			arr[0] += validate_texture_content(file[i]);
		else if (i == 4 || i == 5)
			arr[1] += validate_color_content(file[i]);
		else
			arr[2] += validate_map_content(file[i]);
		i++;
	}
}

int	validate_file_content(char *file_add)
{
	char	**file;
	int		*arr;
	int		error_id;

	file = load_file(file_add);
	arr = ft_calloc(20, sizeof(int));
	validate_file_content_ext(file, arr);
	error_id = 42;
	if (arr[0] != 4)
		error_id = 8;
	else if (arr[1] != 2)
		error_id = 9;
	else if (arr[2] != 0)
		error_id = 6;
	free(arr);
	ft_mtx_free(file);
	return (error_id);
}
