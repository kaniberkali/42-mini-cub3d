/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:43:30 by akaniber          #+#    #+#             */
/*   Updated: 2024/02/23 14:12:55 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	create_map(t_game *game)
{
	const char *map[] = {
		"111111111111111111111111",
		"100000000011000000000001",
		"101100000111000000000001",
		"100100000000000000000001",
		"101100000111000000000001",
		"100000000011000001110111",
		"111101111111111111000001",
		"111101111010101011010101",
		"110000001101010111000001",
		"100000000000000011000001",
		"100000000000000011010101",
		"110000001101010111110111",
		"111101111111011111110111",
		"111101111111001011000001",
		"110000011100000011000001",
		"100000001100000011000001",
		"100000001111111011100011",
		"100000001111111110010101",
		"110000011100011010100011",
		"100000001000001101010101",
		"100000000000000000000001",
		"100000001000001101010101",
		"110000011100011010100011",
		"111111111111111111111111"
	};

	game->map = (char **)malloc(MAP_WIDTH * sizeof(char *));
    for (int i = 0; i < MAP_WIDTH; i++) {
        game->map[i] = (char *)malloc((MAP_HEIGHT + 1) * sizeof(char));
        strcpy(game->map[i], map[i]);
    }
}

int	create_window(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->window = (int **)malloc(WINDOW_HEIGHT * sizeof(int *));
	if (!(game->window))
		return (-1);
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		game->window[i] = (int *)malloc(WINDOW_WIDTH * sizeof(int));
		if (!(game->window[i]))
			return (-1);
		while (j < WINDOW_WIDTH)
		{
			game->window[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

int	create_texture(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->texture = (int **)malloc(sizeof(int *) * 4);
	if (!(game->texture))
		return (-1);
	while (i < 4)
	{
		j = 0;
		game->texture[i] = (int *)malloc(sizeof(int) * \
		(TEXTURE_HEIGHT * TEXTURE_WIDTH));
		if (!(game->texture[i]))
			return (-1);
		while (j < TEXTURE_HEIGHT * TEXTURE_WIDTH)
		{
			game->texture[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}
