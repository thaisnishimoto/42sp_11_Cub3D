/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_layout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:38:58 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/19 14:43:41 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map_layout(t_data *game)
{
	size_t	rows;
	size_t	columns;
	
	game->map.layout = &game->map.content[6];
	if (game->map.layout == NULL)	
		handle_error("Map layout missing.", game, 1);
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
