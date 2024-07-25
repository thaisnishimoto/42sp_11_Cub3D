/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:47:21 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/25 12:17:29 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_images_on_screen(t_data *game)
{
	if (mlx_image_to_window(game->mlx, game->playerview_img, 0, 0) < 0)
		handle_error("Player view image render failed", game, 2);
	game->playerview_img->instances->z = 1;
}

void	create_mlx_images(t_data *game)
{
	game->playerview_img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->playerview_img)
		handle_error("Player view image creation failed", game, 2);
	put_images_on_screen(game);
}
