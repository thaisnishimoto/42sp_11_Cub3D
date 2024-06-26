/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:33:39 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/06/26 16:10:53 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//void	move_forward(t_data *game)
//{
//	game->player.x += 1;
//}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_data	*game;

	(void)keydata;
	game = param;
	if (mlx_is_key_down(game->screen, MLX_KEY_ESCAPE))
		end_game(game);
	if (mlx_is_key_down(game->screen, MLX_KEY_W) || mlx_is_key_down(game->screen, MLX_KEY_UP))
		game->player.y -= 1;
//		move_forward(game);
	if (mlx_is_key_down(game->screen, MLX_KEY_S) ||	mlx_is_key_down(game->screen, MLX_KEY_DOWN))
		game->player.y += 1;
	if (mlx_is_key_down(game->screen, MLX_KEY_A))
		game->player.x -= 1;
	if (mlx_is_key_down(game->screen, MLX_KEY_D))
		game->player.x += 1;
}

int	end_game(void *param)
{
	t_data	*game;

	game = param;
	mlx_close_window(game->screen);
	mlx_delete_image(game->screen, game->background_img);
	mlx_delete_image(game->screen, game->minimap_img);
	mlx_delete_image(game->screen, game->player_img);
	mlx_terminate(game->screen);
	ft_free_matrix(game->map.content);
	free(game);
//	for handle_error call
//	if (game->config_stage < 4)
//		return (1);
	exit (EXIT_SUCCESS);
}
