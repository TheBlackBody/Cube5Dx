/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:18:20 by sfernand          #+#    #+#             */
/*   Updated: 2023/11/20 17:03:19 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

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
	int		step_x;
	int		step_y;
	int		is_hit;
	int		w_side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	step;
	double	tex_pos;
	double	x;
	double	y;
	int		map_x;
	int		map_y;
	double	ig_x;
	double	ig_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delt_dist_x;
	double	delt_dist_y;
	double	len_ray;
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
	int		mouse_x;
	int		mouse_y;
	int		text_width;
	int		text_height;
	int		side;
	char	**f;
	char	**c;
}	t_pose;

typedef struct s_wsize
{
	int	s_x;
	int	s_y;
}	t_wsize;

typedef struct s_image
{
	void	*referenc;
	t_wsize	size;
	void	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_image;

typedef struct s_map_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	**map;
	t_pose	pose;
	t_image	north;
	t_image	south;
	t_image	east;
	t_image	west;
}				t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_w;
	void	*img;
	void	*addr;
	int		line_lenght;
	int		endian;
	int		bits_per_pixel;
	t_pose	*var;
	t_data	*data;
	t_wsize	size;
}	t_mlx;

void		ft_close(void);
void		ft_game(t_mlx *mlx, t_data *data);
void		parse_path(char *path, int time);
void		init_data(char *path, t_data *data);
void		init_no(char *line, t_data *data);
void		init_so(char *line, t_data *data);
void		init_we(char *line, t_data *data);
void		init_ea(char *line, t_data *data);
void		ft_ignit_sprite(t_data *data, t_mlx *mlx);
void		ft_pixel_put(t_mlx *mlx, int x, int y, int color);
void		move_front(int keycode, t_mlx *mlx);
void		move_left(int keycode, t_mlx *mlx);
void		rotat_left(t_mlx *mlx);
void		rotat_right(t_mlx *mlx);
void		put_image(t_mlx *mlx);
void		verif_map(t_data *data);
void		ft_calcul_delt(t_pose *var);
void		ft_calcul_step(t_pose *var);
void		ft_dda(t_pose *var, t_data *data);
void		ft_calculations(t_mlx *mlx, t_data *data);
void		ft_line_height(t_mlx *mlx, t_pose *var, int x, t_data *data);
double		ft_abs(double val);
int			ft_close_w(t_mlx *mlx);
int			ft_calc(t_mlx *mlx);
int			key_hook(int keycode, t_mlx *mlx);
int			mouse_hook(int x, int y, t_mlx *mlx);
int			mcolor(int t, int r, int g, int b);
int			lenx(char **map, int y);
t_image		*ft_select_text(t_pose *var, t_data *data);
void		flood_fill(char **map, int x, int y);
void		flood_fill2(char **map, int x, int y);
int			leny(char **map);
int			lenx(char **map, int y);
void		check_char(char **map, int x, int y);
void		free_map(char **map);
void		utils_data(t_data *data);
void		check_data(t_data *data);
int			check_num(char	*n);
void		check_data_utils(char **f, char **c, int n_f, int n_c);
void		check_map(t_data *data);

#endif
