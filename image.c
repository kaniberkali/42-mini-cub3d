/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:11:05 by akaniber          #+#    #+#             */
/*   Updated: 2024/02/23 13:23:06 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	load_image(t_game *game, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	img->img = mlx_xpm_file_to_image(game->render.mlx, path,
			&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->size_l, &img->endian);
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->render.mlx, img->img);
}

void	load_texture(t_game *game)
{
	t_img	img;

	load_image(game, game->texture[2], "textures/eagleart.xpm", &img);
	load_image(game, game->texture[3], "textures/grayhit.xpm", &img);
	load_image(game, game->texture[0], "textures/graywallshade.xpm", &img);
	load_image(game, game->texture[1], "textures/redbrick.xpm", &img);
}

void	draw(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			game->img.data[y * WINDOW_WIDTH + x] = game->window[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->render.mlx, game->render.window,
		game->img.img, 0, 0);
}
