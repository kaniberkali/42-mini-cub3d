/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:09:04 by akaniber          #+#    #+#             */
/*   Updated: 2024/02/23 13:17:23 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	key_update(t_game *game)
{
	move_vertical(game);
	move_horizontal(game);
	rotate_rigth(game);
	rotate_left(game);
}

int	key_press(int key, t_game *game)
{
	if (key == K_ESC)
	{
		free_window(game);
		free_texture(game);
		memset(&game->key, '\0', sizeof(game->key));
		mlx_destroy_window(game->render.mlx, game->render.window);
		exit(0);
	}
	else if (key == K_W)
		game->key.w = TRUE;
	else if (key == K_A)
		game->key.a = TRUE;
	else if (key == K_S)
		game->key.s = TRUE;
	else if (key == K_D)
		game->key.d = TRUE;
	else if (key == K_AR_L)
		game->key.left = TRUE;
	else if (key == K_AR_R)
		game->key.right = TRUE;
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == K_W)
		game->key.w = FALSE;
	else if (key == K_A)
		game->key.a = FALSE;
	else if (key == K_S)
		game->key.s = FALSE;
	else if (key == K_D)
		game->key.d = FALSE;
	else if (key == K_AR_L)
		game->key.left = FALSE;
	else if (key == K_AR_R)
		game->key.right = FALSE;
	return (0);
}
