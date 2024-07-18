/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:47:21 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/18 14:38:09 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_background(t_data *game)
{
	int	x;
	int	y;

	game->background_img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->background_img)
        	handle_error("Background image creation failed", game, 1);
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
	if (mlx_image_to_window(game->mlx, game->background_img, 0, 0) < 0)
        	handle_error("Background image render failed", game, 1);
	game->background_img->instances->z = 1;
}
