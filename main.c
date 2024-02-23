/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 20:28:54 by yohlee            #+#    #+#             */
/*   Updated: 2024/02/23 14:13:16 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	main(void)
{
	t_game	game;
	int		check_1;
	int		check_2;

	game.render.mlx = mlx_init();
	first_init(&game);
	create_map(&game);
	check_1 = create_window(&game);
	if (check_1 == -1)
		return (-1);
	memset(&game.key, 0, sizeof(game.key));
	check_2 = create_texture(&game);
	if (check_2 == -1)
		return (-1);
	load_texture(&game);
	load_mlx(&game);
}
