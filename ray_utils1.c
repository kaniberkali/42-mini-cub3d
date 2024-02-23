/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:52:04 by akaniber          #+#    #+#             */
/*   Updated: 2024/02/23 13:24:24 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	calc_floor_ceiling(t_game *game, int floor, int ceiling)
{
	int	y;
	int	x;

	y = WINDOW_HEIGHT / 2 + 1;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			game->window[y][x] = floor;
			game->window[WINDOW_HEIGHT - y - 1][x] = ceiling;
			x++;
		}
		y++;
	}
}

int	set_draw_start(int line_height)
{
	int	draw_start;

	draw_start = -line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	return (draw_start);
}

int	set_draw_end(int line_height)
{
	int	draw_end;

	draw_end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw_end >= WINDOW_HEIGHT)
		draw_end = WINDOW_HEIGHT - 1;
	return (draw_end);
}

double	set_wall_x(t_ray_casting *ray, t_game *game)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = game->player.y + ray->wall_dist * ray->ray_diry;
	else
		wall_x = game->player.x + ray->wall_dist * ray->ray_dirx;
	wall_x -= floor((wall_x));
	return (wall_x);
}
