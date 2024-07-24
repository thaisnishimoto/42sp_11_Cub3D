/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:38:58 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/24 00:39:02 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	str[i] = '\0';
	while (str && *str == ' ')
		str++;
	return (str);
}

void	get_wall_textures(t_data *game)
{
	char	**map_content;
	int		i;

	map_content = game->map.content;
	i = 0;
	while (map_content[i])
	{
		if (!ft_strncmp(map_content[i], "NO", 2))
			game->map.north_tex = mlx_load_png(skip_spaces(&map_content[i][3]));
		else if (!ft_strncmp(map_content[i], "SO", 2))
			game->map.south_tex = mlx_load_png(skip_spaces(&map_content[i][3]));
		else if (!ft_strncmp(map_content[i], "WE", 2))
			game->map.west_tex = mlx_load_png(skip_spaces(&map_content[i][3]));
		else if (!ft_strncmp(map_content[i], "EA", 2))
			game->map.east_tex = mlx_load_png(skip_spaces(&map_content[i][3]));
		i++;
	}
	if (!game->map.north_tex || !game->map.south_tex
		|| !game->map.west_tex || !game->map.east_tex)
		handle_error("Wall texture load failed", game, 1);
}

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
