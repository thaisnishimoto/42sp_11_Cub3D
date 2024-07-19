/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:12:43 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/19 17:22:28 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	shoot_weapon(t_data *game)
{
	static int	frame;

	if (frame >= 0 && frame <= REPEAT_FRAME)
	{
		game->shoot = true;
		game->wand_img[0]->enabled = false;
		game->wand_img[1]->enabled = true;
	}
	if (frame > REPEAT_FRAME && frame <= REPEAT_FRAME * 2)
	{
		game->wand_img[1]->enabled = false;
		game->wand_img[2]->enabled = true;
	}
	if (frame > REPEAT_FRAME * 2 && frame <= REPEAT_FRAME * 3)
	{
		game->wand_img[2]->enabled = false;
		game->wand_img[3]->enabled = true;
	}
	if (frame > REPEAT_FRAME * 3)
	{
		game->wand_img[3]->enabled = false;
		game->wand_img[0]->enabled = true;
		frame = 0;
		game->shoot = false;
	}
	frame++;
}