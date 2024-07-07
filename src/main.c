/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:38:58 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/06 18:28:35 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//static void error(void)
//{
//	puts(mlx_strerror(mlx_errno));
//	exit(EXIT_FAILURE);
//}

void	handle_error(char *msg, int errno_set)
{
	write(STDERR_FILENO, "Error\n", 6);
	if (errno_set)
	{
		perror(msg);
		exit(EXIT_FAILURE);
	}
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

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
	int i = 0;
	while (game->map.layout[i])
	{
		printf("%s", game->map.layout[i]);
		i++;
	}
	init_game(game);
	return (EXIT_SUCCESS);
}
