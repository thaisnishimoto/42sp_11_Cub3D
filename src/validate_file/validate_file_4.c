/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:25:23 by mchamma           #+#    #+#             */
/*   Updated: 2024/07/23 11:32:05 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flood_fill(char **file, int x, int y, int *open_map)
{
	int	m;
	int	n;

	m = ft_strlen(file[x]);
	n = ft_mtx_size(file);
	if (file[x][y] == ' ')
		(*open_map)++;
	if (x < 0 || x > n || y < 0 || y > m)
		return ;
	if (file[x][y] != '0')
		return ;
	if (x == 6 || x == n - 1 || y == 0 || y == m - 1)
		(*open_map)++;
	file[x][y] = '.';
	if (x + 1 < n)
		flood_fill(file, x + 1, y, open_map);
	if (x - 1 >= 0)
		flood_fill(file, x - 1, y, open_map);
	if (y + 1 < m)
		flood_fill(file, x, y + 1, open_map);
	if (y - 1 >= 0)
		flood_fill(file, x, y - 1, open_map);
}

int	validate_map_game(char *file_add)
{
	char	**file;
	int		*player;
	int		error_id;
	int		open_map;

	file = load_file(file_add);
	player = load_player(file);
	error_id = 42;
	open_map = 0;
	if (player[0] != 1)
		error_id = 10;
	else
	{
		flood_fill(file, player[1], player[2], &open_map);
		if (open_map != 0)
			error_id = 11;
	}
	free(player);
	ft_mtx_free(file);
	return (error_id);
}
