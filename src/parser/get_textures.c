/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:41:06 by mchamma           #+#    #+#             */
/*   Updated: 2024/07/25 12:47:18 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_wall_textures(t_data *game)
{
	char	**map_content;

	map_content = game->map.content;
	game->map.north_tex = mlx_load_png(map_content[0]);
	game->map.south_tex = mlx_load_png(map_content[1]);
	game->map.east_tex = mlx_load_png(map_content[2]);
	game->map.west_tex = mlx_load_png(map_content[3]);
}
