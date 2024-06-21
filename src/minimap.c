/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:47:21 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/06/21 18:44:47 by tmina-ni         ###   ########.fr       */
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
//	int	scale;
//
//	if (game->map.layout_rows > game->map.layout_columns)
//		scale = HEIGHT / game->map.layout_rows;
//	else
//		scale = WIDTH / game->map.layout_columns;
	game->minimap_img = mlx_new_image(game->screen, HEIGHT, WIDTH);
	if (!game->minimap_img)
        	handle_error("Minimap image creation failed.", 0);
	minimap.y = 0;
	while (minimap.y < game->map.layout_rows)
	{
		minimap.x = 0;
//		ft_printf("row len: %d\n", ft_strlen(game->map.layout[minimap.y]));
//		while (minimap.x < game->map.layout_columns)
//		while (minimap.x < 10)
		while (minimap.x < ft_strlen(game->map.layout[minimap.y]))
		{
//			ft_printf("y: %d | x: %d | row len: %d\n", minimap.y, minimap.x, ft_strlen(game->map.layout[minimap.y]));
			draw_pos.x = minimap.x * 5;
			draw_pos.y = minimap.y * 5;
	//		ft_printf("draw pos x: %d y: %d\n", draw_pos.x, draw_pos.y);
			if (game->map.layout[minimap.y][minimap.x] == '1')
				draw_tile(game->minimap_img, &draw_pos, 5, game->map.floor_color);
			else if (game->map.layout[minimap.y][minimap.x] == '0')
				draw_tile(game->minimap_img, &draw_pos, 5, game->map.ceiling_color);
			else
				draw_tile(game->minimap_img, &draw_pos, 5, 0);
//				mlx_put_pixel(game->minimap_img, minimap.x, minimap.y, game->map.floor_color); 
			minimap.x++;
		}
		minimap.y++;
	}
	if (mlx_image_to_window(game->screen, game->minimap_img, 0, 0) < 0)
        	handle_error("Minimap image render failed.", 0);
}

//void	draw_minimap(t_data *game)
//{
//	unsigned int	height;
//	unsigned int	width;
//	unsigned int	x;
//	unsigned int	y;
//
//	height = game->map.layout_rows * SCALE;
//	width = game->map.layout_columns * SCALE;
//	game->minimap_img = mlx_new_image(game->screen, height, width);
//	if (!game->minimap_img)
//        	handle_error("Minimap image creation failed.", 0);
//	y = 0;
//	while (y < height)
//	{
//		x = 0;
//		while (x < ft_strlen(game->map.layout[y]) - 1)
//		{
//			unsigned int	rx = x / SCALE;
//			unsigned int	ry = y / SCALE;
//			printf("x = %d | y = %d | rx = %d | ry = %d\n", x, y, rx, ry);
////			if (rx < game->map.layout_columns && ry < game->map.layout_rows)
////			{
////			if (game->map.layout[rx][ry] == '1')
////				mlx_put_pixel(game->minimap_img, x, y, game->map.floor_color); 
//	//		x += SCALE;
//			x++;
//		}
//	//	y += SCALE;
//		y++;
//	}
//	if (mlx_image_to_window(game->screen, game->minimap_img, 5, 5) < 0)
//        	handle_error("Minimap image render failed.", 0);
//}
