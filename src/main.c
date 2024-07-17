/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:38:58 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/17 13:47:05 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*game;

	(void)argc;
	game = ft_calloc(1, sizeof(t_data));
//	init_struct
	game->map.path = argv[1];
//	validate_map();
	parse_map(game);
//	printf("%s\n", game.map.north_tex_path);
//	printf("%s\n", game.map.south_tex_path);
//	printf("%s\n", game.map.west_tex_path);
//	printf("%s\n", game.map.east_tex_path);
//	printf("%x\n", game.map.floor_color);
//	printf("%x\n", game.map.ceiling_color);
//	int i = 0;
//	while (game->map.layout[i])
//	{
//		printf("%s", game->map.layout[i]);
//		i++;
//	}
	init_game(game);
	return (EXIT_SUCCESS);
}
