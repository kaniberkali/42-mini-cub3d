/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:47:47 by akaniber          #+#    #+#             */
/*   Updated: 2024/02/23 14:25:22 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	main_loop(t_game *game)
{
	calc(game);
	draw(game);
	key_update(game);
	return (0);
}

void	first_init(t_game *game)
{
	game->player.x = 21.0;
	game->player.y = 11.5;
	game->direction.x = -1.0;
	game->direction.y = 0.0;
	game->plane.x = 0.0;
	game->plane.y = 0.66;
	game->move_speed = 0.05;
	game->rotation_speed = 0.05;
}

int	close_prog(t_game *game)
{
	exit(0);
}

void	load_mlx(t_game *game)
{
	game->render.window = mlx_new_window(game->render.mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "https://kaniberk.com");
	game->img.img = mlx_new_image(game->render.mlx, WINDOW_WIDTH \
	, WINDOW_HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.size_l, &game->img.endian);
	mlx_loop_hook(game->render.mlx, &main_loop, game);
	mlx_hook(game->render.window, X_EVENT_KEY_PRESS, 0, &key_press, game);
	mlx_hook(game->render.window, 17, 42, close_prog, &game);
	mlx_hook(game->render.window, X_EVENT_KEY_RELEASE, 0, &key_release, game);
	mlx_loop(game->render.mlx);
}
