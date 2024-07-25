/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:24:54 by mchamma           #+#    #+#             */
/*   Updated: 2024/07/25 15:05:55 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	error_file(int i)
{
	ft_putstr_fd("Error\n", 2);
	if (i == 1)
		ft_putstr_fd("Incorrect quantity of arguments\n", 2);
	else if (i == 2)
		ft_putstr_fd("Incorrect file name or extension\n", 2);
	else if (i == 3)
		ft_putstr_fd("Unable to read the file\n", 2);
	else if (i == 4)
		ft_putstr_fd("File has incorrect qty of elements\n", 2);
	else if (i == 5)
		ft_putstr_fd("File has an incomplete map\n", 2);
	else if (i == 6)
		ft_putstr_fd("File has unidentified content\n", 2);
	else if (i == 7)
		ft_putstr_fd("File has content after map\n", 2);
	else if (i == 8)
		ft_putstr_fd("File has incorrect texture specification\n", 2);
	else if (i == 9)
		ft_putstr_fd("File has incorrect color specification\n", 2);
	else if (i == 10)
		ft_putstr_fd("Map must have just one player\n", 2);
	else if (i == 11)
		ft_putstr_fd("Player shouldn't reach empty space\n", 2);
	exit (1);
}

int	validate_file_name(char *file_add)
{
	size_t	file_len;
	size_t	ext_len;

	file_len = ft_strlen(file_add);
	ext_len = ft_strlen(".cub");
	if (file_len <= ext_len || ft_strcmp(&file_add[file_len - 4], ".cub"))
		return (0);
	return (1);
}

void	validate_file(int argc, char **argv)
{
	int		error_id;

	if (argc != 2)
		error_file(1);
	if (!validate_file_name(argv[1]))
		error_file(2);
	error_id = validate_file_count(argv[1]);
	if (error_id != 42)
		error_file(error_id);
	error_id = validate_file_content(argv[1]);
	if (error_id != 42)
		error_file(error_id);
	error_id = validate_map_game(argv[1]);
	if (error_id != 42)
		error_file(error_id);
}
