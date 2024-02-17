/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 20:28:54 by yohlee            #+#    #+#             */
/*   Updated: 2024/02/17 15:14:40 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int main_loop(t_game *game)
{
	calc(game);
	draw(game);
	key_update(game);
	return (0);
}


int main(void)
{
	t_game game;
	game.render.mlx = mlx_init();

	game.player.x = 21.0;
	game.player.y = 11.5;
	game.direction.x = -1.0;
	game.direction.y = 0.0;
	game.plane.x = 0.0;
	game.plane.y = 0.66;
	memset(&game.key, 0, sizeof(game.key));
	game.window = (int **)malloc(height * sizeof(int *));
	for (int i = 0; i < height; i++)
        game.window[i] = (int *)malloc(width * sizeof(int));
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			game.window[i][j] = 0;
		}
	}

	if (!(game.texture = (int **)malloc(sizeof(int *) * 11)))
		return (-1);
	for (int i = 0; i < 11; i++)
	{
		if (!(game.texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth))))
			return (-1);
	}
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < texHeight * texWidth; j++)
		{
			game.texture[i][j] = 0;
		}
	}

	load_texture(&game);

	game.move_speed = 0.05;
	game.rotation_speed = 0.05;

	game.render.window = mlx_new_window(game.render.mlx, width, height, "mlx");

	game.img.img = mlx_new_image(game.render.mlx, width, height);
	game.img.data = (int *)mlx_get_data_addr(game.img.img, &game.img.bpp, &game.img.size_l, &game.img.endian);

	mlx_loop_hook(game.render.mlx, &main_loop, &game);
	mlx_hook(game.render.window, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.render.window, X_EVENT_KEY_RELEASE, 0, &key_release, &game);

	mlx_loop(game.render.mlx);
}
