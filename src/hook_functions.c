/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:33:39 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/06 22:58:58 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_player(t_data *game, float speed)
{
	t_vector	velocity;

	velocity.x = game->dir.x * speed;
	velocity.y = game->dir.y * speed;
	game->player.x += velocity.x * game->frame_time;
	game->player.y += velocity.y * game->frame_time;
}

void	move_player_left(t_data *game, float speed)
{
	t_vector	velocity;

	velocity.x = game->dir.y * speed;
	velocity.y = -game->dir.x * speed;
	game->player.x += velocity.x * game->frame_time;
	game->player.y += velocity.y * game->frame_time;
}

void	move_player_right(t_data *game, float speed)
{
	t_vector	velocity;

	velocity.x = -game->dir.y * speed;
	velocity.y = game->dir.x * speed;
	game->player.x += velocity.x * game->frame_time;
	game->player.y += velocity.y * game->frame_time;
}

void	rotate_player(t_data *game, float speed)
{
	float	old_x;

	old_x = game->dir.x;
	game->dir.x = game->dir.x * cos(speed * game->frame_time) - game->dir.y * sin(speed * game->frame_time);
	game->dir.y = old_x * sin(speed * game->frame_time) + game->dir.y * cos(speed * game->frame_time);
	old_x = game->plane.x;
	game->plane.x = game->plane.x * cos(speed * game->frame_time) - game->plane.y * sin(speed * game->frame_time);
	game->plane.y = old_x * sin(speed * game->frame_time) + game->plane.y * cos(speed * game->frame_time);
}

void	key_press(void *param)
{
	t_data	*game;

	game = param;
	if (mlx_is_key_down(game->screen, MLX_KEY_ESCAPE))
		end_game(game);
	if (mlx_is_key_down(game->screen, MLX_KEY_W) || mlx_is_key_down(game->screen, MLX_KEY_UP))
		move_player(game, SPEED);
	if (mlx_is_key_down(game->screen, MLX_KEY_S) ||	mlx_is_key_down(game->screen, MLX_KEY_DOWN))
		move_player(game, -SPEED);
	if (mlx_is_key_down(game->screen, MLX_KEY_A))
		move_player_left(game, SPEED);
	if (mlx_is_key_down(game->screen, MLX_KEY_D))
		move_player_right(game, SPEED);
	if (mlx_is_key_down(game->screen, MLX_KEY_RIGHT))
		rotate_player(game, ROTATE_SPEED);
	if (mlx_is_key_down(game->screen, MLX_KEY_LEFT))
		rotate_player(game, -ROTATE_SPEED);
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
