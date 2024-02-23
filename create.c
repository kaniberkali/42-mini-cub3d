/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:43:30 by akaniber          #+#    #+#             */
/*   Updated: 2024/02/23 13:22:45 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

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
	game->texture = (int **)malloc(sizeof(int *) * 11);
	if (!(game->texture))
		return (-1);
	while (i < 11)
	{
		j = 0;
		game->texture[i] = (int *)malloc(sizeof(int) * (TEXTURE_HEIGHT * TEXTURE_WIDTH));
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
