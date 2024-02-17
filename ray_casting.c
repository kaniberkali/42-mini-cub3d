/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:14:24 by akaniber          #+#    #+#             */
/*   Updated: 2024/02/17 15:20:22 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	calc_floor_ceiling(t_game	*game, int floor, int ceiling)
{
	for (int y = height / 2 + 1; y < height; ++y)
	{	
		for (int x = 0; x < width; ++x)
		{
			game->window[y][x] = floor;
			game->window[height - y - 1][x] = ceiling;
		}
	}
}

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
	return ray;
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
		if (worldMap[ray.mapx][ray.mapy] > 0)
			hit = 1;
	}
	if (ray.side == 0)
		ray.wall_dist = (ray.mapx - game->player.x + (1 - ray.stepx) / 2) / ray.ray_dirx;
	else
		ray.wall_dist = (ray.mapy - game->player.y + (1 - ray.stepy) / 2) / ray.ray_diry;
	return ray;
}

t_ray_casting	ray_init(t_game *game, int x)
{
	t_ray_casting	ray;

	memset(&ray, 0, sizeof(ray));
	ray.camera_x = 2 * x / (double)width - 1;
	ray.ray_dirx = game->direction.x + game->plane.x * ray.camera_x;
	ray.ray_diry = game->direction.y + game->plane.y * ray.camera_x;
	ray.mapx = game->player.x;
	ray.mapy = game->player.y;
	ray.delta_distx = fabs(1 / ray.ray_dirx);
	ray.delta_disty = fabs(1 / ray.ray_diry);

	ray = ray_init_1(game, ray);
	ray = ray_init_2(game, ray);
	return ray;
}

int	ray_get_texture_id(t_ray_casting ray)
{
	if (ray.side == 0 && ray.ray_dirx > 0)
		return 0;
	else if (ray.side == 0 && ray.ray_dirx < 0)
		return 1;
	else if (ray.side == 1 && ray.ray_diry > 0)
		return 2;
	else
		return 3;
}

void calc(t_game *game)
{
	t_ray_casting	ray;
	calc_floor_ceiling(game, 0x252525, 0x379234);


	for (int x = 0; x < width; x++)
	{	
		ray = ray_init(game, x);
		
		int lineHeight = (int)(height / ray.wall_dist);
		int drawStart = -lineHeight / 2 + height / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + height / 2;
		if (drawEnd >= height)
			drawEnd = height - 1;

		double wallX;
		if (ray.side == 0)
			wallX = game->player.y + ray.wall_dist * ray.ray_diry;
		else
			wallX = game->player.x + ray.wall_dist * ray.ray_dirx;
		wallX -= floor((wallX));
		int texX = (int)(wallX * (double)texWidth);
				
		double step = 1.0 * texHeight / lineHeight;
		double texPos = (drawStart - height / 2 + lineHeight / 2) * step;


		for (int y = drawStart; y < drawEnd; y++)
		{
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
			int color = game->texture[ray_get_texture_id(ray)][texHeight * texY + texX];
			game->window[y][x] = color;
		}
	}
}