/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:45:16 by akaniber          #+#    #+#             */
/*   Updated: 2024/02/23 14:02:59 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	free_2d(void **array, int length)
{
	while (--length)
		free(array[length]);
	free(array);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < MAP_HEIGHT)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

void	free_window(t_game *game)
{
	int	i;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		free(game->window[i]);
		i++;
	}
	free(game->window);
	game->window = NULL;
}

void	free_texture(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(game->texture[i]);
		i++;
	}
	free(game->texture);
	game->texture = NULL;
}
