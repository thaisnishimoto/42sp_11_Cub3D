/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:12:43 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/18 12:48:19 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_weapon_textures(t_data *game)
{
	int	i;

	game->map.weapon_texture[0] = mlx_load_png("./textures/weapon/wand_0.png");
	game->map.weapon_texture[1] = mlx_load_png("./textures/weapon/wand_1.png");
	game->map.weapon_texture[2] = mlx_load_png("./textures/weapon/wand_2.png");
	game->map.weapon_texture[3] = mlx_load_png("./textures/weapon/wand_3.png");
	game->map.weapon_texture[4] = mlx_load_png("./textures/weapon/wand_4.png");
	i = 0;
	while (i < WEAPON_FRAMES)
	{
		game->weapon_img[i] = mlx_texture_to_image(game->mlx, game->map.weapon_texture[i]);
		//handle_error("Player image render failed.", 0);
		game->weapon_img[i]->enabled = false;
		mlx_image_to_window(game->mlx, game->weapon_img[i], WIDTH / 2, HEIGHT - game->weapon_img[i]->height);
		game->weapon_img[i]->instances->z = 5;
		i++;
	}
	while (i >= 0)
	{
		//handle_error
		if (game->weapon_img[i] == NULL)
			printf("Weapon loading failed\n");
		i--;
	}
	game->shoot = false;
	game->weapon_img[0]->enabled = true;
}

void	mouse_click(void *param)
{
	t_data	*game;

	game = param;
	if (game->shoot || mlx_is_mouse_down(game->mlx, MLX_MOUSE_BUTTON_LEFT))
		shoot_weapon(game);
}

void	shoot_weapon(t_data *game)
{
	static int	frame;

	if (frame >= 0 && frame <= REPEAT_FRAME)
	{
		game->shoot = true;
		game->weapon_img[0]->enabled = false;
		game->weapon_img[1]->enabled = true;
	}
	if (frame > REPEAT_FRAME && frame <= REPEAT_FRAME * 2)
	{
		game->weapon_img[1]->enabled = false;
		game->weapon_img[2]->enabled = true;
	}
	if (frame > REPEAT_FRAME * 2 && frame <= REPEAT_FRAME * 3)
	{
		game->weapon_img[2]->enabled = false;
		game->weapon_img[3]->enabled = true;
	}
	if (frame > REPEAT_FRAME * 3 && frame <= REPEAT_FRAME * 4)
	{
		game->weapon_img[3]->enabled = false;
		game->weapon_img[4]->enabled = true;
	}
	if (frame > REPEAT_FRAME * 4)
	{
		game->weapon_img[4]->enabled = false;
		game->weapon_img[0]->enabled = true;
		frame = 0;
		game->shoot = false;
	}
	frame++;
}
