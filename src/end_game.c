/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:46:22 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/18 19:12:34 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_error(char *msg, t_data *game, int stage)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	if (stage > 0)
	{
		ft_free_matrix(game->map.content);
		if (stage > 1)
		{
			mlx_close_window(game->mlx);
			mlx_terminate(game->mlx);
			free(game);
		}
	}
	exit(EXIT_FAILURE);
}

void	end_game(void *param)
{
	t_data	*game;

	game = param;
	mlx_close_window(game->mlx);
//	mlx_delete_image(game->mlx, game->background_img);
//	mlx_delete_image(game->mlx, game->minimap_img);
//	mlx_delete_texture;
	mlx_terminate(game->mlx);
	ft_free_matrix(game->map.content);
	free(game);
	exit (EXIT_SUCCESS);
}
