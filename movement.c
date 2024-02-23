/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:48:21 by akaniber          #+#    #+#             */
/*   Updated: 2024/02/23 14:27:02 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	move_vertical(t_game *game)
{
	if (game->key.w)
	{
		if (game->map[(int)(game->player.x
				+ game->direction.x * game->move_speed)]
				[(int)(game->player.y)] == SPACE)
			game->player.x += game->direction.x * game->move_speed;
		if (game->map[(int)(game->player.x)][(int)(game->player.y
				+ game->direction.y * game->move_speed)] == SPACE)
			game->player.y += game->direction.y * game->move_speed;
	}
	if (game->key.s)
	{
		if (game->map[(int)(game->player.x
				- game->direction.x * game->move_speed)]
				[(int)(game->player.y)] == SPACE)
			game->player.x -= game->direction.x * game->move_speed;
		if (game->map[(int)(game->player.x)][(int)(game->player.y
				- game->direction.y * game->move_speed)] == SPACE)
			game->player.y -= game->direction.y * game->move_speed;
	}
}

void	move_horizontal(t_game *game)
{
	if (game->key.a)
	{
		if (game->map[(int)(game->player.x
				- game->direction.y * game->move_speed)]
				[(int)(game->player.y)] == SPACE)
			game->player.x -= game->direction.y * game->move_speed;
		if (game->map[(int)(game->player.x)][(int)(game->player.y
				+ game->direction.x * game->move_speed)] == SPACE)
			game->player.y += game->direction.x * game->move_speed;
	}
	if (game->key.d)
	{
		if (game->map[(int)(game->player.x
				+ game->direction.y * game->move_speed)]
				[(int)(game->player.y)] == SPACE)
			game->player.x += game->direction.y * game->move_speed;
		if (game->map[(int)(game->player.x)][(int)(game->player.y
				- game->direction.x * game->move_speed)] == SPACE)
			game->player.y -= game->direction.x * game->move_speed;
	}
}

void	rotate_rigth(t_game *game)
{
	double	old_dirx;
	double	old_planex;

	if (game->key.right)
	{
		old_dirx = game->direction.x;
		game->direction.x = game->direction.x * cos(-game->rotation_speed)
			- game->direction.y * sin(-game->rotation_speed);
		game->direction.y = old_dirx * sin(-game->rotation_speed)
			+ game->direction.y * cos(-game->rotation_speed);
		old_planex = game->plane.x;
		game->plane.x = game->plane.x * cos(-game->rotation_speed)
			- game->plane.y * sin(-game->rotation_speed);
		game->plane.y = old_planex * sin(-game->rotation_speed)
			+ game->plane.y * cos(-game->rotation_speed);
	}
}

void	rotate_left(t_game *game)
{
	double	old_dirx;
	double	old_planex;

	if (game->key.left)
	{
		old_dirx = game->direction.x;
		game->direction.x = game->direction.x * cos(game->rotation_speed)
			- game->direction.y * sin(game->rotation_speed);
		game->direction.y = old_dirx * sin(game->rotation_speed)
			+ game->direction.y * cos(game->rotation_speed);
		old_planex = game->plane.x;
		game->plane.x = game->plane.x * cos(game->rotation_speed)
			- game->plane.y * sin(game->rotation_speed);
		game->plane.y = old_planex * sin(game->rotation_speed)
			+ game->plane.y * cos(game->rotation_speed);
	}
}
