/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:35:41 by mchamma           #+#    #+#             */
/*   Updated: 2024/07/25 12:46:13 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_content(t_data *game, char **file)
{
	int		i;
	size_t	rows;

	rows = file_rows(game->map.path);
	game->map.content = ft_calloc(rows + 1, sizeof(char *));
	i = 0;
	while (file[i])
	{
		game->map.content[i] = ft_strdup(file[i]);
		i++;
	}
	game->map.content_rows = rows;
}

void	parse_map(t_data *game)
{
	char	**file;
	int		*player;

	file = load_file(game->map.path);
	player = load_player(file);
	get_content(game, file);
	get_player_pos(game, player);
	get_map_layout(game);
	get_background_colors(game);
	get_wall_textures(game);
	ft_mtx_free(file);
	free(player);
}
