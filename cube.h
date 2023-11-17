/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:18:20 by sfernand          #+#    #+#             */
/*   Updated: 2023/11/17 23:48:30 by gpolve-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdlib.h> //a retirer
# include "./libft/libft.h"
# include "./ft_printf/printf.h"
# include "./get_next_line/get_next_line.h"

/* This struct is for the position of the player and what he sees.
dir is the direction vector and plane the camera plane (which is more a line
since it's 2d)...etc. */

typedef struct s_pose
{
	int	step_x;
	int	step_y;
	int	is_hit; //yes or no
	int	w_side; // N S E W ?
	int	line_height;
	int	draw_start;
	int	draw_end;
	double	step;
	double	tex_pos;
	double	x;
	double	y;
	int	map_x;
	int	map_y;
	double	ig_x;
	double	ig_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delt_dist_x;
	double	delt_dist_y;
	double	len_ray; //perpwalldist in the tuto
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	cur_time;
	double	prev_time;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	move_speed;
	double	rot_speed;
	int	mouse_x;
	int	mouse_y;
	int	text_width;
	int	text_height;
	int	side; // supp ensuite
}	t_pose;

typedef struct s_wsize
{
	int	s_x;
	int	s_y;
}	t_wsize;

/* The next two sruct are for the assets */

//typedef struct	s_vector
//{
 //   int	x;
  //  int	y;
//}                t_vector;

typedef struct	s_image
{
	void	*referenc;
//	t_vector	size;
	t_wsize		size;
	char	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
//	void	*mlx;
//	void	*img
}	t_image;

typedef struct s_map_data
{
	char    *NO;
	char    *SO;
	char    *WE;
	char    *EA;
	char    *F;
	char    *C;
	char    **map;
//	char	***mape; //ntm c'est pour test, ca me fait mal a moi aussi;
	t_pose	pose;
	t_image	north;
	t_image	south;
	t_image	east;
	t_image	west;
//	t_mlx	mlx;
}              t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_w;
	void	*img;
	void	*addr;
	int	line_lenght;
	int	endian;
	int	bits_per_pixel;
//	int	field;
//	int	sky;
	t_pose	*var;
	t_data *data;
	t_wsize	size;
}	t_mlx;

void    ft_close(void);
void	ft_game(t_mlx *mlx, t_data *data);
void    parse_path(char *path, int time);
void	init_data(char *path, t_data *data);
void    init_NO(char *line, t_data *data);
void    init_SO(char *line, t_data *data);
void    init_WE(char *line, t_data *data);
void    init_EA(char *line, t_data *data);
void	ft_ignit_sprite(t_data *data, t_mlx *mlx);
void	ft_pixel_put(t_mlx *mlx, int x, int y, int color);
void	move_front(int keycode, t_mlx *mlx);
void	move_left(int keycode, t_mlx *mlx);
void	rotat_left(t_mlx *mlx);
void	rotat_right(t_mlx *mlx);
void	put_image(t_mlx *mlx);
void    verif_map(t_data *data);
void	ft_calculations(t_mlx *mlx, t_data *data);
double	ft_abs(double val);
int	ft_close_w(t_mlx *mlx);
int	ft_calc(t_mlx *mlx);
int	key_hook(int keycode, t_mlx *mlx);
int	mouse_hook(int x, int y, t_mlx *mlx);
int	mcolor(int t, int r, int g, int b);
//int    get_pixel_color(t_image *text, int x, int y); //a sup pt
int     lenx(char **map, int y);
t_image	*ft_select_text(t_pose *var, t_data *data);

#endif
