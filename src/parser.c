/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:38:58 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/06/17 17:14:08 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	get_file_rows(t_data *game)
{
	int	fd;
	int	count;
	char	*line;

	fd = open(game->map.path, O_RDWR);
	if (fd == -1)
		handle_error("Open failed", 1);
	count = 0;
	line = ft_get_next_line(fd);
	while (line)
	{
		if (ft_strcmp(line, "\n"))
			count++;
		free(line);
		line = ft_get_next_line(fd);
	}
	if (close(fd) == -1)
		handle_error("Close failed", 1);
	return (count);
}

void	allocate_file_content(t_data *game)
{
	int	fd;
	int	i;
	char	*line;

	game->map.rows = get_file_rows(game);
	fd = open(game->map.path, O_RDWR);
	if (fd == -1)
		handle_error("Open failed", 1);
	game->map.content = ft_calloc(game->map.rows + 1, sizeof(char *));
	i = 0;
	line = ft_get_next_line(fd);
	while (line)
	{
		if (ft_strcmp(line, "\n"))
		{
			game->map.content[i] = ft_strdup(line);
			i++;
		}
		free(line);
		line = ft_get_next_line(fd);
	}
	if (close(fd) == -1)
		handle_error("Close failed", 1);
}

char	*skip_spaces(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

void	get_textures(t_data *game)
{
	int	i;

	i = 0;
	while (game->map.content[i])
	{
		if (!ft_strncmp(game->map.content[i], "NO", 2))
			game->map.north_texture_path = skip_spaces(&game->map.content[i][2]);
		else if (!ft_strncmp(game->map.content[i], "SO", 2))
			game->map.south_texture_path = skip_spaces(&game->map.content[i][2]);
		else if (!ft_strncmp(game->map.content[i], "WE", 2))
			game->map.west_texture_path = skip_spaces(&game->map.content[i][2]);
		else if (!ft_strncmp(game->map.content[i], "EA", 2))
			game->map.east_texture_path = skip_spaces(&game->map.content[i][2]);
		i++;
	}
}

int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	get_background_colors(t_data *game)
{
	int	i;
	char	*colors;
	char	**rgb;

	i = 0;
	while (game->map.content[i])
	{
		if (!ft_strncmp(game->map.content[i], "F", 1))
		{
			colors = skip_spaces(&game->map.content[i][1]);
			rgb = ft_split(colors, ',');
			game->map.floor_color = get_rgba(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]), 255);
			ft_free_matrix(rgb);
		}
		else if (!ft_strncmp(game->map.content[i], "C", 1))
		{
			colors = skip_spaces(&game->map.content[i][1]);
			rgb = ft_split(colors, ',');
			game->map.ceiling_color = get_rgba(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]), 255);
			ft_free_matrix(rgb);
		}
		i++;
	}
}

void	parse_map(t_data *game)
{
	allocate_file_content(game);
	get_textures(game);
	get_background_colors(game);
//	get_map_layout();
}
