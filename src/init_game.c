/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:47:21 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/04 23:51:08 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_background(t_data *game)
{
	int	x;
	int	y;

	game->background_img = mlx_new_image(game->screen, WIDTH, HEIGHT);
	if (!game->background_img)
        	handle_error("Background image creation failed.", 0);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(game->background_img, x, y, game->map.ceiling_color);
			else
				mlx_put_pixel(game->background_img, x, y, game->map.floor_color);
			x++;
		}
		y++;
	}
	if (mlx_image_to_window(game->screen, game->background_img, 0, 0) < 0)
        	handle_error("Background image render failed.", 0);
	game->background_img->instances->z = 1;
}

void	init_game(t_data *game)
{
	game->screen = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	if (!game->screen)
        	handle_error("Mlx init failed.", 0);
	draw_background(game);
	draw_minimap(game);
	mlx_close_hook(game->screen, (void *)end_game, game);
	mlx_loop_hook(game->screen, key_press, game);
	mlx_loop_hook(game->screen, render_player, game);
	mlx_loop_hook(game->screen, raycast, game);
	raycast(game);
	mlx_loop(game->screen);
}
