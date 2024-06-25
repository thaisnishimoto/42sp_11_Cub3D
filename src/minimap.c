/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:47:21 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/06/25 17:23:19 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_tile(mlx_image_t *img, t_pos *pos, size_t size, int color)
{
	size_t	current_x;
	size_t	current_y;

	current_y = pos->y;
	while (current_y < (pos->y + size))
	{
		current_x = pos->x;
		while (current_x < (pos->x + size))
		{
			mlx_put_pixel(img, current_x, current_y, color); 
			current_x++;
		}
		current_y++;
	}
}

void	draw_minimap(t_data *game)
{
	t_pos	minimap;
	t_pos	draw_pos;
	int	scale;

	if (game->map.layout_rows > game->map.layout_columns)
		scale = MINI_HEIGHT / game->map.layout_rows;
	else
		scale = MINI_WIDTH / game->map.layout_columns;
	game->minimap_img = mlx_new_image(game->screen, MINI_WIDTH, MINI_HEIGHT);
	if (!game->minimap_img)
        	handle_error("Minimap image creation failed.", 0);
	minimap.y = 0;
	while (minimap.y < game->map.layout_rows)
	{
		minimap.x = 0;
		while (minimap.x < ft_strlen(game->map.layout[minimap.y]))
		{
			draw_pos.x = minimap.x * scale;
			draw_pos.y = minimap.y * scale;
			if (game->map.layout[minimap.y][minimap.x] == '1')
				draw_tile(game->minimap_img, &draw_pos, scale, game->map.floor_color);
			else if (game->map.layout[minimap.y][minimap.x] == '0')
				draw_tile(game->minimap_img, &draw_pos, scale, game->map.ceiling_color);
			else
				draw_tile(game->minimap_img, &draw_pos, scale, 0);
//				mlx_put_pixel(game->minimap_img, minimap.x, minimap.y, game->map.floor_color); 
			minimap.x++;
		}
		minimap.y++;
	}
	if (mlx_image_to_window(game->screen, game->minimap_img, scale, scale) < 0)
        	handle_error("Minimap image render failed.", 0);
}
