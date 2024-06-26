/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:38:58 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/06/25 17:42:14 by tmina-ni         ###   ########.fr       */
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

	game->map.content_rows = get_file_rows(game);
	fd = open(game->map.path, O_RDWR);
	if (fd == -1)
		handle_error("Open failed", 1);
	game->map.content = ft_calloc(game->map.content_rows + 1, sizeof(char *));
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

void	parse_map(t_data *game)
{
	allocate_file_content(game);
	get_textures(game);
	get_background_colors(game);
	get_map_layout(game);
	get_player_pos(game);
}
