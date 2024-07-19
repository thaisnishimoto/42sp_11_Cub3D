/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:38:58 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/19 17:22:47 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//And replaces new line at end for \0
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
	int	i;

	i = 0;
	while (game->map.content[i])
	{
		if (!ft_strncmp(game->map.content[i], "NO", 2))
		{
			game->map.north_tex_path = skip_spaces(&game->map.content[i][3]);
			game->map.north_tex = mlx_load_png(game->map.north_tex_path);
		}
		else if (!ft_strncmp(game->map.content[i], "SO", 2))
		{
			game->map.south_tex_path = skip_spaces(&game->map.content[i][3]);
			game->map.south_tex = mlx_load_png(game->map.south_tex_path);
		}
		else if (!ft_strncmp(game->map.content[i], "WE", 2))
		{
			game->map.west_tex_path = skip_spaces(&game->map.content[i][3]);
			game->map.west_tex = mlx_load_png(game->map.west_tex_path);
		}
		else if (!ft_strncmp(game->map.content[i], "EA", 2))
		{
			game->map.east_tex_path = skip_spaces(&game->map.content[i][3]);
			game->map.east_tex = mlx_load_png(game->map.east_tex_path);
		}
		i++;
	}
	//check if any texture == NULL
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
