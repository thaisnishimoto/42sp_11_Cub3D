/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:12:43 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/25 11:50:17 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	change_frame_img(t_data *game, int num)
{
	game->wand_img[num]->enabled = false;
	game->wand_img[(num + 1) % WEAPON_FRAMES]->enabled = true;
}

void	shoot_weapon(t_data *game)
{
	static int	frame;

	if (frame >= 0 && frame <= REPEAT_FRAME)
	{
		game->shoot = true;
		change_frame_img(game, 0);
	}
	if (frame > REPEAT_FRAME && frame <= REPEAT_FRAME * 2)
		change_frame_img(game, 1);
	if (frame > REPEAT_FRAME * 2 && frame <= REPEAT_FRAME * 3)
		change_frame_img(game, 2);
	if (frame > REPEAT_FRAME * 3)
	{
		change_frame_img(game, 3);
		frame = 0;
		game->shoot = false;
	}
	frame++;
}
