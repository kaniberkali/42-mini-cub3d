/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:11:05 by akaniber          #+#    #+#             */
/*   Updated: 2024/02/17 15:13:40 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void load_image(t_game *game, int *texture, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(game->render.mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	for (int y = 0; y < img->img_height; y++)
		for (int x = 0; x < img->img_width; x++)
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
	mlx_destroy_image(game->render.mlx, img->img);
}

void load_texture(t_game *game)
{
	t_img img;

	load_image(game, game->texture[2], "textures/eagleart.xpm", &img);
	load_image(game, game->texture[3], "textures/grayhit.xpm", &img);
	load_image(game, game->texture[0], "textures/graywallshade.xpm", &img);
	load_image(game, game->texture[1], "textures/redbrick.xpm", &img);
}

void draw(t_game *game)
{
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			game->img.data[y * width + x] = game->window[y][x];
	mlx_put_image_to_window(game->render.mlx, game->render.window, game->img.img, 0, 0);
}