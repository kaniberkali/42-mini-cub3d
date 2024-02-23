/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:53:05 by akaniber          #+#    #+#             */
/*   Updated: 2024/02/23 14:14:32 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

t_ray_casting	ray_init_1(t_game *game, t_ray_casting ray)
{
	if (ray.ray_dirx < 0)
	{
		ray.stepx = -1;
		ray.side_distx = (game->player.x - ray.mapx) * ray.delta_distx;
	}
	else
	{
		ray.stepx = 1;
		ray.side_distx = (ray.mapx + 1.0 - game->player.x) * ray.delta_distx;
	}
	if (ray.ray_diry < 0)
	{
		ray.stepy = -1;
		ray.side_disty = (game->player.y - ray.mapy) * ray.delta_disty;
	}
	else
	{
		ray.stepy = 1;
		ray.side_disty = (ray.mapy + 1.0 - game->player.y) * ray.delta_disty;
	}
	return (ray);
}

double	calc_wall_dist(t_ray_casting *ray, t_game *game)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->mapx - game->player.x
				+ (1 - ray->stepx) / 2) / ray->ray_dirx;
	else
		ray->wall_dist = (ray->mapy - game->player.y
				+ (1 - ray->stepy) / 2) / ray->ray_diry;
	return (ray->wall_dist);
}

t_ray_casting	ray_init_2(t_game *game, t_ray_casting ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray.side_distx < ray.side_disty)
		{
			ray.side_distx += ray.delta_distx;
			ray.mapx += ray.stepx;
			ray.side = 0;
		}
		else
		{
			ray.side_disty += ray.delta_disty;
			ray.mapy += ray.stepy;
			ray.side = 1;
		}
		if (game->map[ray.mapx][ray.mapy] == WALL)
			hit = 1;
	}
	ray.wall_dist = calc_wall_dist(&ray, game);
	return (ray);
}

t_ray_casting	ray_init(t_game *game, int x)
{
	t_ray_casting	ray;

	memset(&ray, 0, sizeof(ray));
	ray.camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	ray.ray_dirx = game->direction.x + game->plane.x * ray.camera_x;
	ray.ray_diry = game->direction.y + game->plane.y * ray.camera_x;
	ray.mapx = game->player.x;
	ray.mapy = game->player.y;
	ray.delta_distx = fabs(1 / ray.ray_dirx);
	ray.delta_disty = fabs(1 / ray.ray_diry);
	ray = ray_init_1(game, ray);
	ray = ray_init_2(game, ray);
	return (ray);
}
