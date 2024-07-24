/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:38:58 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/23 23:30:24 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_rgba(char *colors)
{
	char	**rgb;
	int	r;
	int	g;
	int	b;

	rgb = ft_split(colors, ',');
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	ft_mtx_free(rgb);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	get_background_colors(t_data *game)
{
	int	i;
	char	*colors;

	i = 0;
	while (game->map.content[i])
	{
		if (!ft_strncmp(game->map.content[i], "F", 1))
		{
			colors = skip_spaces(&game->map.content[i][1]);
			if (colors[0] == '\n')
				handle_error("Missing floor color.", game, 1);
			game->map.floor_color = get_rgba(colors);
			if (game->map.floor_color == -1)
				handle_error("Color out of range", game, 1);
		}
		else if (!ft_strncmp(game->map.content[i], "C", 1))
		{
			colors = skip_spaces(&game->map.content[i][1]);
			if (colors[0] == '\n')
				handle_error("Missing ceiling color.", game, 1);
			game->map.ceiling_color = get_rgba(colors);
			if (game->map.floor_color == -1)
				handle_error("Color out of range", game, 1);
		}
		i++;
	}
}
