/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_layout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:38:58 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/06/18 18:01:50 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_map_layout(t_data *game)
{
	int	i;

	i = 6;
	game->map.layout = &game->map.content[i];
	if (game->map.layout == NULL)
		handle_error("Map layout missing.", 0);
}
