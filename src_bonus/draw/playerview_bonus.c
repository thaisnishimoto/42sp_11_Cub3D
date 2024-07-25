/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerview_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:47:21 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/25 11:50:51 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_background(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(game->playerview_img, x, y,
					game->map.ceiling_color);
			else
				mlx_put_pixel(game->playerview_img, x, y,
					game->map.floor_color);
			x++;
		}
		y++;
	}
}

static void	update_fps(t_data *game)
{
	char				*fps;
	char				*fps_str;
	static int			i;
	static mlx_image_t	*fps_img;

	game->frame_time = game->mlx->delta_time;
	if (i++ % 15 == 0)
	{
		fps = ft_itoa(1 / game->frame_time);
		fps_str = ft_strjoin("FPS: ", fps);
		free(fps);
		if (fps_img)
			mlx_delete_image(game->mlx, fps_img);
		fps_img = mlx_put_string(game->mlx, fps_str, WIDTH - 75, HEIGHT - 20);
		fps_img->instances->z = 4;
		free(fps_str);
	}
}

void	draw_playerview(void *param)
{
	t_data	*game;

	game = param;
	draw_background(game);
	update_fps(game);
	raycast_walls(game);
}
