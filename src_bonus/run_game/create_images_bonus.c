/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:47:21 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/25 11:39:38 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	put_images_on_screen(t_data *game)
{
	t_coord	pos;
	int		i;

	if (mlx_image_to_window(game->mlx, game->playerview_img, 0, 0) < 0)
		handle_error("Player view image render failed", game, 2);
	game->playerview_img->instances->z = 1;
	if (mlx_image_to_window(game->mlx, game->minimap_img, 1, 1) < 0)
		handle_error("Minimap image render failed", game, 2);
	game->minimap_img->instances->z = 2;
	i = 0;
	while (i < WEAPON_FRAMES)
	{
		pos.x = WIDTH / 2;
		pos.y = HEIGHT - game->wand_img[i]->height;
		if (mlx_image_to_window(game->mlx, game->wand_img[i], pos.x, pos.y) < 0)
			handle_error("Weapon image render failed", game, 2);
		game->wand_img[i]->instances->z = 3;
		i++;
	}
	game->shoot = false;
	game->wand_img[0]->enabled = true;
}

void	create_mlx_images(t_data *game)
{
	int	i;

	game->playerview_img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->playerview_img)
		handle_error("Player view image creation failed", game, 2);
	game->minimap_img = mlx_new_image(game->mlx, MINI_WIDTH, MINI_HEIGHT);
	if (!game->minimap_img)
		handle_error("Minimap image creation failed", game, 2);
	i = 0;
	while (i < WEAPON_FRAMES)
	{
		game->wand_img[i] = mlx_texture_to_image(game->mlx, game->wand_tex[i]);
		if (!game->wand_img[i])
			handle_error("Wand image creation failed", game, 2);
		game->wand_img[i]->enabled = false;
		i++;
	}
	put_images_on_screen(game);
}
