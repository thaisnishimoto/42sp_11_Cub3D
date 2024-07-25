/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:41:06 by mchamma           #+#    #+#             */
/*   Updated: 2024/07/25 12:44:11 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	get_weapon_textures(t_data *game)
{
	int	i;

	game->wand_tex[0] = mlx_load_png("./textures/weapon/wand_0.png");
	game->wand_tex[1] = mlx_load_png("./textures/weapon/wand_1.png");
	game->wand_tex[2] = mlx_load_png("./textures/weapon/wand_2.png");
	game->wand_tex[3] = mlx_load_png("./textures/weapon/wand_3.png");
	i = 0;
	while (i < WEAPON_FRAMES)
	{
		if (!game->wand_tex[i])
			handle_error("Weapon texture load failed", game, 1);
		i++;
	}
}

void	get_wall_textures(t_data *game)
{
	char	**map_content;

	map_content = game->map.content;
	game->map.north_tex = mlx_load_png(map_content[0]);
	game->map.south_tex = mlx_load_png(map_content[1]);
	game->map.east_tex = mlx_load_png(map_content[2]);
	game->map.west_tex = mlx_load_png(map_content[3]);
}
