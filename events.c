/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:09:04 by akaniber          #+#    #+#             */
/*   Updated: 2024/02/17 15:13:43 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"


void key_update(t_game *game)
{
	if (game->key.w)
	{
		if (!worldMap[(int)(game->player.x + game->direction.x * game->move_speed)][(int)(game->player.y)])
			game->player.x += game->direction.x * game->move_speed;
		if (!worldMap[(int)(game->player.x)][(int)(game->player.y + game->direction.y * game->move_speed)])
			game->player.y += game->direction.y * game->move_speed;
	}
	if (game->key.s)
	{
		if (!worldMap[(int)(game->player.x - game->direction.x * game->move_speed)][(int)(game->player.y)])
			game->player.x -= game->direction.x * game->move_speed;
		if (!worldMap[(int)(game->player.x)][(int)(game->player.y - game->direction.y * game->move_speed)])
			game->player.y -= game->direction.y * game->move_speed;
	}
	if (game->key.a)
	{
		if (!worldMap[(int)(game->player.x - game->direction.y * game->move_speed)][(int)(game->player.y)])
			game->player.x -= game->direction.y * game->move_speed;
		if (!worldMap[(int)(game->player.x)][(int)(game->player.y + game->direction.x * game->move_speed)])
			game->player.y += game->direction.x * game->move_speed;
	}

	if (game->key.d)
	{
		if (!worldMap[(int)(game->player.x + game->direction.y * game->move_speed)][(int)(game->player.y)])
			game->player.x += game->direction.y * game->move_speed;
		if (!worldMap[(int)(game->player.x)][(int)(game->player.y - game->direction.x * game->move_speed)])
			game->player.y -= game->direction.x * game->move_speed;
	}
	if (game->key.right)
	{
		double oldDirX = game->direction.x;
		game->direction.x = game->direction.x * cos(-game->rotation_speed) - game->direction.y * sin(-game->rotation_speed);
		game->direction.y = oldDirX * sin(-game->rotation_speed) + game->direction.y * cos(-game->rotation_speed);
		double oldPlaneX = game->plane.x;
		game->plane.x = game->plane.x * cos(-game->rotation_speed) - game->plane.y * sin(-game->rotation_speed);
		game->plane.y = oldPlaneX * sin(-game->rotation_speed) + game->plane.y * cos(-game->rotation_speed);
	}
	if (game->key.left)
	{
		double oldDirX = game->direction.x;
		game->direction.x = game->direction.x * cos(game->rotation_speed) - game->direction.y * sin(game->rotation_speed);
		game->direction.y = oldDirX * sin(game->rotation_speed) + game->direction.y * cos(game->rotation_speed);
		double oldPlaneX = game->plane.x;
		game->plane.x = game->plane.x * cos(game->rotation_speed) - game->plane.y * sin(game->rotation_speed);
		game->plane.y = oldPlaneX * sin(game->rotation_speed) + game->plane.y * cos(game->rotation_speed);
	}
	if (game->key.esc)
		exit(0);
}

int key_press(int key, t_game *game)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W)
		game->key.w = 1;
	else if (key == K_A)
		game->key.a = 1;
	else if (key == K_S)
		game->key.s = 1;
	else if (key == K_D)
		game->key.d = 1;
	else if (key == K_AR_L)
		game->key.left = 1;
	else if (key == K_AR_R)
		game->key.right = 1;
	return (0);
}

int key_release(int key, t_game *game)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W)
		game->key.w = 0;
	else if (key == K_A)
		game->key.a = 0;
	else if (key == K_S)
		game->key.s = 0;
	else if (key == K_D)
		game->key.d = 0;
	else if (key == K_AR_L)
		game->key.left = 0;
	else if (key == K_AR_R)
		game->key.right = 0;
	return (0);
}