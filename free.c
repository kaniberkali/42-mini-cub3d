/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:45:16 by akaniber          #+#    #+#             */
/*   Updated: 2024/02/23 13:22:52 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

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
	while (i < 11)
	{
		free(game->texture[i]);
		i++;
	}
	free(game->texture);
	game->texture = NULL;
}
