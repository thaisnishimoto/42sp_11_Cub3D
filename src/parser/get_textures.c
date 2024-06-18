/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:38:58 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/06/17 22:46:36 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*skip_spaces(char *str)
{
	while (str && *str == ' ')
		str++;
	return (str);
}

void	get_textures(t_data *game)
{
	int	i;

	i = 0;
	while (game->map.content[i])
	{
		if (!ft_strncmp(game->map.content[i], "NO", 2))
			game->map.north_tex_path = skip_spaces(&game->map.content[i][2]);
		else if (!ft_strncmp(game->map.content[i], "SO", 2))
			game->map.south_tex_path = skip_spaces(&game->map.content[i][2]);
		else if (!ft_strncmp(game->map.content[i], "WE", 2))
			game->map.west_tex_path = skip_spaces(&game->map.content[i][2]);
		else if (!ft_strncmp(game->map.content[i], "EA", 2))
			game->map.east_tex_path = skip_spaces(&game->map.content[i][2]);
		i++;
	}
	//check if any texture == NULL
}
