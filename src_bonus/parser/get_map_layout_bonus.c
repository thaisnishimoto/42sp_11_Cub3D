/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_layout_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:15:25 by mchamma           #+#    #+#             */
/*   Updated: 2024/07/25 12:42:54 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	get_map_layout(t_data *game)
{
	size_t	rows;
	size_t	columns;

	game->map.layout = &game->map.content[6];
	rows = 0;
	columns = 0;
	while (game->map.layout[rows])
	{
		if (columns < ft_strlen(game->map.layout[rows]))
			columns = ft_strlen(game->map.layout[rows]);
		rows++;
	}
	game->map.layout_rows = rows;
	game->map.layout_columns = columns;
}
