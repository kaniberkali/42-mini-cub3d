/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:07:48 by akaniber          #+#    #+#             */
/*   Updated: 2024/02/23 15:01:13 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
#define LIBRARY_H

#include "mlx/mlx.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

# define TRUE 1
# define FALSE 0
# define K_A 0
# define K_D 2
# define K_W 13
# define K_S 1
# define K_AR_L 123
# define K_AR_R 124
# define K_ESC 53
#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_RELEASE 3
#define TEXTURE_WIDTH 64
#define TEXTURE_HEIGHT 64
#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 800
#define WALL '1'
#define SPACE '0'

typedef struct s_ray_casting
{
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		side;
	double	camera_x;
	double	ray_dirx;
	double	ray_diry;
	double	side_distx;
	double	side_disty;
	double	delta_distx;
	double	delta_disty;
	double	wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		tex_y;
	int		color;
}				t_ray_casting;

typedef struct s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_key
{
	int	a;
	int	w;
	int	s;
	int	d;
	int	esc;
	int	left;
	int	right;
} t_key;

typedef struct s_point
{
	double x;
	double y;
} t_point;

typedef	struct s_render
{
	void	*mlx;
	void	*window;
}	t_render;


typedef struct s_game
{
	t_point 	player;
	t_point 	direction;
	t_point		plane;
	t_render	render;	
	t_key 		key;
	t_img 		img;
	int 		**window;
	int 		**texture;
	double 		move_speed;
	double 		rotation_speed;
	char		**map;
} t_game;


void key_update(t_game *game);
void load_image(t_game *game, int *texture, char *path, t_img *img);
void load_texture(t_game *game);
void draw(t_game *game);
int key_press(int key, t_game *game);
int key_release(int key, t_game *game);
void	calc_floor_ceiling(t_game	*game, int floor, int ceiling);
t_ray_casting	ray_init_1(t_game *game, t_ray_casting ray);
t_ray_casting	ray_init_2(t_game *game, t_ray_casting ray);
t_ray_casting	ray_init(t_game *game, int x);
int	ray_get_texture_id(t_ray_casting ray);
void calc(t_game *game);

void	move_vertical(t_game *game);
void	move_horizontal(t_game *game);
void	rotate_rigth(t_game *game);
void	rotate_left(t_game *game);

int create_window(t_game *game);
int create_texture(t_game *game);


double	set_wall_x(t_ray_casting *ray,t_game *game);
int		set_draw_end(int line_height);
int		set_draw_start(int line_height);
void	calc_floor_ceiling(t_game *game, int floor, int ceiling);
t_ray_casting ray_init(t_game *game, int x);
void free_window(t_game *game);
void free_texture(t_game *game);

void	first_init(t_game *game);
void	load_mlx(t_game *game);
void	free_map(t_game *game);
void	create_map(t_game *game);
void	free_2d(void **array, int length);

#endif