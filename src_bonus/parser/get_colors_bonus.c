/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:05:23 by mchamma           #+#    #+#             */
/*   Updated: 2024/07/25 12:42:39 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_rgba(char *color)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(color, ',');
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	ft_mtx_free(rgb);
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	get_background_colors(t_data *game)
{
	char	*color;

	color = game->map.content[4];
	game->map.floor_color = get_rgba(color);
	color = game->map.content[5];
	game->map.ceiling_color = get_rgba(color);
}
