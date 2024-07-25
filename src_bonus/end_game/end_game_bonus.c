/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:46:22 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/25 11:51:29 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	delete_textures(t_data *game)
{
	if (game->map.north_tex)
		mlx_delete_texture(game->map.north_tex);
	if (game->map.south_tex)
		mlx_delete_texture(game->map.south_tex);
	if (game->map.west_tex)
		mlx_delete_texture(game->map.west_tex);
	if (game->map.east_tex)
		mlx_delete_texture(game->map.east_tex);
	if (game->wand_tex[0])
		mlx_delete_texture(game->wand_tex[0]);
	if (game->wand_tex[1])
		mlx_delete_texture(game->wand_tex[1]);
	if (game->wand_tex[2])
		mlx_delete_texture(game->wand_tex[2]);
	if (game->wand_tex[3])
		mlx_delete_texture(game->wand_tex[3]);
}

void	handle_error(char *msg, t_data *game, int stage)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	if (stage > 0)
	{
		ft_mtx_free(game->map.content);
		delete_textures(game);
		if (stage > 1)
		{
			mlx_close_window(game->mlx);
			mlx_terminate(game->mlx);
		}
	}
	free(game);
	exit(EXIT_FAILURE);
}

void	end_game(void *param)
{
	t_data	*game;

	game = param;
	mlx_close_window(game->mlx);
	delete_textures(game);
	mlx_terminate(game->mlx);
	ft_mtx_free(game->map.content);
	free(game);
	exit (EXIT_SUCCESS);
}
