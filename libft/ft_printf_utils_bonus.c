/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:23:34 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/08/04 14:52:16 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_hash_flag(const char *format);
static char	*ft_plus_flag(void);
static char	*ft_space_flag(void);

int	ft_check_flags(const char *format)
{
	int	result;

	result = 0;
	if (*format == '#' || *format == '+' || *format == ' ')
		result = 1;
	return (result);
}

char	*ft_get_flag(const char *format)
{
	int		i;
	char	*flag_buffer;

	i = 0;
	flag_buffer = NULL;
	if (format[i++] == '#')
		flag_buffer = ft_hash_flag(&format[i]);
	if (*format == '+')
		flag_buffer = ft_plus_flag();
	if (*format == ' ')
		flag_buffer = ft_space_flag();
	return (flag_buffer);
}

static char	*ft_hash_flag(const char *format)
{
	char	*flag_buffer;

	flag_buffer = malloc(3 * sizeof(char));
	if (flag_buffer == NULL)
		return (NULL);
	flag_buffer[0] = '0';
	if (*format == 'x')
		flag_buffer[1] = 'x';
	if (*format == 'X')
		flag_buffer[1] = 'X';
	flag_buffer[2] = '\0';
	return (flag_buffer);
}

static char	*ft_plus_flag(void)
{
	char	*flag_buffer;

	flag_buffer = malloc(2 * sizeof(char));
	if (flag_buffer == NULL)
		return (NULL);
	flag_buffer[0] = '+';
	flag_buffer[1] = '\0';
	return (flag_buffer);
}

static char	*ft_space_flag(void)
{
	char	*flag_buffer;

	flag_buffer = malloc(2 * sizeof(char));
	if (flag_buffer == NULL)
		return (NULL);
	flag_buffer[0] = ' ';
	flag_buffer[1] = '\0';
	return (flag_buffer);
}
