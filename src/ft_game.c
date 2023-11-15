/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:49:33 by gpolve-g          #+#    #+#             */
/*   Updated: 2023/11/15 13:09:38 by gpolve-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

//not working
static double	ft_abs(double val)
{
	if (val < 0)
		val = val * -1;
	return (val);
}

static	void	ft_calcul_delt(t_pose *var)
{
	var->delt_dist_x = 1e30;
	if (var->ray_dir_x != 0)
		var->delt_dist_x = ft_abs(1 / var->ray_dir_x); //faut ajuster
	var->delt_dist_y = 1e30;
	if (var->ray_dir_y != 0)
		var->delt_dist_y = ft_abs(1 / var->ray_dir_y); //faut ajuster
}

static	void	ft_calcul_step(t_pose *var)
{
	if (var->ray_dir_x < 0)
	{
		var->step_x = -1;
		var->side_dist_x = (var->x - var->map_x) * var->delt_dist_x; //j'ai reverif et c'est bien ca, ce qui fait 0 mais bon;
	}
	else
	{
		var->step_x = 1;
		var->side_dist_x = (var->map_x + 1 - var->x) * var->delt_dist_x; //toujours
	}
	if (var->ray_dir_y < 0)
	{
		var->step_y = -1;
		var->side_dist_y = (var->y - var->map_y) * var->delt_dist_y;
	}
	else
	{
		var->step_y = 1;
		var->side_dist_y = (var->map_y + 1 - var->y) * var->delt_dist_y; //toujours
	}	
}

static	void	ft_dda(t_pose *var, t_data *data)
{
	while (var->is_hit == 0)
	{
		if (var->side_dist_x < var->side_dist_y)
		{
			var->side_dist_x += var->delt_dist_x;
			var->map_x += var->step_x;
			var->w_side = 0;
		}
		else
		{
			var->side_dist_y += var->delt_dist_y;
			var->map_y += var->step_y;
			var->w_side = 1;
		}
		if (data->map[var->map_y][var->map_x] == '1')
			var->is_hit = 1;
	}
	if (var->w_side == 0)
		var->len_ray = var->side_dist_x - var->delt_dist_x;
	else
		var->len_ray = var->side_dist_y - var->delt_dist_y;
}

static	t_image	*ft_select_text(t_pose *var, t_data *data)
{
	if (var->w_side == 1)
	{
		if (var->map_y < (int)var->y)
		{
//			var->side = 2;
			return (&data->south);
		}
		else
		{
//			var->side = 1;
			return (&data->north);
		}
	}
	else
	{
		if (var->map_x > (int)var->x)
		{
//			var->side = 3;
			return (&data->west);
		}
		else
		{
//			var->side = 4;
			return (&data->east);
		}
	}
}

static int	text_color(t_image *w_text, t_pose *var, int tex_x)
{
	int	tex_y;
	int	color;

//	if (var->side == 1)
//		return(mcolor(0, 155, 0, 0));
//	if (var->side == 2)
//		return(mcolor(0, 0, 155, 0));
//	if (var->side == 3)
//		return(mcolor(0, 0, 0, 155));
//	if (var->side == 4)
//		return(mcolor(0, 155, 155, 0));
	tex_y = (int)var->tex_pos; //manque la secu si overflow
	if (var->tex_pos > 2147483647.0)
		tex_y = var->text_height - 1;
	var->tex_pos += var->step;
	color = w_text->pixels[var->text_height * tex_y + tex_x];
	return (color);
}
//t_data temp
static	void	ft_put_line(t_mlx *mlx, t_pose *var, int x, t_data *data)
{
	int		y;
	t_image		*w_text;
	double		wall_x;
	int		tex_x;
	char	**F;
	char	**C;

	F = ft_split(data->F, ',');
	C = ft_split(data->C, ',');
	w_text = ft_select_text(var, data);
	if (var->w_side == 0)
		wall_x = var->y + var->len_ray * var->ray_dir_y;
	else
		wall_x = var->x + var->len_ray * var->ray_dir_x;
	wall_x -= (double)((int)wall_x);
	tex_x = (int)(wall_x * (double)var->text_width);
	if (var->w_side == 0 && var->ray_dir_x > 0)
		tex_x = var->text_width - tex_x - 1;
	if (var->w_side == 1 && var->ray_dir_x < 0)
		tex_x = var->text_width - tex_x - 1;

//		color = mcolor(0, 255, 0, 0);// if w_side == 0 and wall > y player north
//		if (var->w_side == 1) // if x wall > x player alors west else east
//			color = mcolor(0, 255 / 2, 0, 0);
//	}
	var->step = 1.0 * var->text_height / var->line_height;
	var->tex_pos = (var->draw_start - mlx->size.s_y / 2 + var->line_height / 2) * var->step;
	y = -1;
	//	color = color / 2;
	while (++y < mlx->size.s_y)
	{
		//	ft_printf("y = %i\n", y);
		if (y >= var->draw_start && y <= var->draw_end)
		{
		//	ft_printf("y = %i, oui\n", y);
			ft_pixel_put(mlx, x, y, text_color(w_text, var, tex_x));
		}
		else if (y < var->draw_end)
			ft_pixel_put(mlx, x, y, mcolor(0, ft_atoi(C[0]), ft_atoi(C[1]), ft_atoi(C[2])));
		else
		{
		//	ft_printf("y = %i, non\n", y);
			//	ft_printf("non\n");
			ft_pixel_put(mlx, x, y, mcolor(0, ft_atoi(F[0]), ft_atoi(F[1]), ft_atoi(F[2])));
		}
	}
}

//t_data temp
static	void	ft_line_height(t_mlx *mlx, t_pose *var, int x, t_data *data)
{

//	int	line_height;
	var->line_height = (int)(mlx->size.s_y / var->len_ray);
	var->draw_start = -var->line_height / 2 + mlx->size.s_y / 2;
	if (var->draw_start < 0)
		var->draw_start = 0;
	var->draw_end = var->line_height / 2 + mlx->size.s_y / 2;
	if (var->draw_end >= mlx->size.s_y)
		var->draw_end = mlx->size.s_y - 1;
	ft_put_line(mlx, var, x, data);
}

static	void	ft_calculations(t_mlx *mlx, t_data *data)
{
	int	x;
	t_pose	var; //avant c'etait un pointeur;

//	ft_printf("coucou\n");
	var = *mlx->var;
//	while (1)
//	{
	x = -1;
//	ft_printf("coucou\n");
	while (++x < mlx->size.s_x)
	{
//	ft_printf("COUCOU\n");
		var.camera_x = 2 * x / (double)mlx->size.s_x - 1;
		var.ray_dir_x = var.dir_x + var.plane_x * var.camera_x;
		var.ray_dir_y = var.dir_y + var.plane_y * var.camera_x;
		var.map_x = (int)var.x;
		var.map_y = (int)var.y;
		//	var->ig_x = (double)var->x;
		//	var->ig_y = (double)var->y;
		ft_calcul_delt(&var);
		var.is_hit = 0;
		ft_calcul_step(&var);
		ft_dda(&var, data);
//	ft_printf("bonsoir\n");
		ft_line_height(mlx, &var, x, data);
	}
//	ft_printf("BONSOIR\n");
	put_image(mlx);
//	}
	//	return ;
}

int	ft_close_w(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_w);
	exit(0);
	return (0);
}

void	move_left(int keycode, t_mlx *mlx)
{
	t_pose *var;
	t_data *data;

	data = mlx->data;
	var = mlx->var;
	if (keycode == 0)
	{
		if (data->map[(int)var->y][(int)(var->x - var->dir_x * (var->move_speed * 1.2))] == '0')
			var->x -= var->dir_y * var->move_speed;
		if (data->map[(int)(var->y + var->dir_y * (var->move_speed * 1.2))][(int)var->x] == '0')
			var->y += var->dir_x * var->move_speed;
	}
	if (keycode == 2)
	{
		if (data->map[(int)var->y][(int)(var->x + var->dir_x * (var->move_speed * 1.2))] == '0')
			var->x += var->dir_y * var->move_speed;
		if (data->map[(int)(var->y - var->dir_y * (var->move_speed * 1.2))][(int)var->x] == '0')
			var->y -= var->dir_x * var->move_speed;
	}
	ft_calc(mlx);
}

void	move_front(int keycode, t_mlx *mlx)
{
	t_pose *var;
	t_data *data;

	data = mlx->data;
	var = mlx->var;
	if (keycode == 13)
	{
	if (data->map[(int)var->y][(int)(var->x + var->dir_x * (var->move_speed))] == '0')
		var->x += var->dir_x * var->move_speed;
	if (data->map[(int)(var->y + var->dir_y * (var->move_speed))][(int)var->x] == '0')
		var->y += var->dir_y * var->move_speed;
	}
	if (keycode == 1)
	{
	if (data->map[(int)var->y][(int)(var->x - var->dir_x * (var->move_speed))] == '0')
		var->x -= var->dir_x * var->move_speed;
	if (data->map[(int)(var->y - var->dir_y * (var->move_speed))][(int)var->x] == '0')
		var->y -= var->dir_y * var->move_speed;
	}
	ft_calc(mlx);
}

void	rotat_right(t_mlx *mlx)
{
	double	oldir_x;
	double	old_plane;
	t_pose *var;

	var = mlx->var;
	oldir_x = var->dir_x;
	old_plane = var->plane_x;
	var->dir_x = var->dir_x * cos(-var->rot_speed) - var->dir_y * sin(-var->rot_speed);
	var->dir_y = oldir_x * sin(-var->rot_speed) + var->dir_y * cos(-var->rot_speed);
	var->plane_x = var->plane_x * cos(-var->rot_speed) - var->plane_y * sin(-var->rot_speed);
	var->plane_y = old_plane * sin(-var->rot_speed) + var->plane_y * cos(-var->rot_speed);
	ft_calc(mlx);
}

void	rotat_left(t_mlx *mlx)
{
	double	oldir_x;
	double	old_plane;
	t_pose *var;

	var = mlx->var;
	oldir_x = var->dir_x;
	old_plane = var->plane_x;
	var->dir_x = var->dir_x * cos(var->rot_speed) - var->dir_y * sin(var->rot_speed);
	var->dir_y = oldir_x * sin(var->rot_speed) + var->dir_y * cos(var->rot_speed);
	var->plane_x = var->plane_x * cos(var->rot_speed) - var->plane_y * sin(var->rot_speed);
	var->plane_y = old_plane * sin(var->rot_speed) + var->plane_y * cos(var->rot_speed);
	ft_calc(mlx);
}

int	key_hook(int keycode, t_mlx *mlx)
{
//	ft_printf("pre_test data\n");
//	ft_printf("test data : data NO = %s\n", mlx->data->NO);
//	ft_printf("keycode = %i\n", keycode);
	if (keycode == 53)
		ft_close_w(mlx);
	else if (keycode == 0 || keycode == 2) //a || d
		move_left(keycode, mlx);
//	else if (keycode == 2) //d
//		move_right();
	else if (keycode == 13 || keycode == 1) //w || s
		move_front(keycode, mlx);
//	else if (keycode == 1) //s
//		move_back();
	else if (keycode == 123) //left
		rotat_left(mlx);
	else if (keycode == 124) //right
		rotat_right(mlx);
	return (0);
}

int	mouse_hook(int x, int y, t_mlx *mlx)
{
	t_pose *var;

	var = mlx->var;
//	(void)mlx;
	if (var->mouse_x == -2147483648 && var->mouse_y == -2147483648)
	{
		var->mouse_x = x;
		var->mouse_y = y;
		return (0);
	}
	if (var->mouse_x < x)
	{
		var->mouse_x = x;
		rotat_right(mlx);
	}
	else if (var->mouse_x > x)
	{
		var->mouse_x = x;
		rotat_left(mlx);
	}
//	ft_printf("x = %i, y = %i\n", x, y);
	return (0);
}

int	ft_calc(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, mlx->size.s_x,
			mlx->size.s_y);
	mlx->addr = mlx_get_data_addr(mlx->img,
			&mlx->bits_per_pixel, &mlx->line_lenght,
			&mlx->endian);
	ft_calculations(mlx, mlx->data);
	return (0);
}

void	ft_game(t_mlx *mlx, t_data *data)
{
//	free(data->map);
//	data->mape = worldmap;
	//	ft_printf("%p\n", mlx->mlx);
//	ft_printf("coucou sasha\n");
	mlx->var = &data->pose;
//	mlx->var->x = 22;
//	mlx->var->y = 12;
	ft_calculations(mlx, mlx->data);
//	mlx_key_hook(mlx->mlx_w, key_hook, mlx);
//	mlx_mouse_hook(mlx->mlx_w, mouse_hook, mlx);
	mlx_hook(mlx->mlx_w, 17, (1L << 19), ft_close_w, mlx);
	mlx_hook(mlx->mlx_w, 6, 0L, mouse_hook, mlx);
	mlx_hook(mlx->mlx_w, 2, 1L << 0, key_hook, mlx);
//	mlx_loop_hook(mlx, ft_calc, mlx);
	mlx_loop(mlx->mlx);
}
//au cas ou;
//	else if (data->map[var->map_y][var->map_x] == 2)
//	{
//		color = mcolor(0, 0, 255, 0);
//		if (var->w_side == 1)
//			color = mcolor(0, 0, 255 / 2, 0);
//	}
//	else if (data->map[var->map_y][var->map_x] == 3)
//	{
//		color = mcolor(0, 0, 0, 255);
//		if (var->w_side == 1)
//			color = mcolor(0, 0, 0, 255 / 2);
//	}
//	else if (data->map[var->map_y][var->map_x] == 4)
//	{
//		color = mcolor(0, 255, 255, 255);
//		if (var->w_side == 1)
//			color = mcolor(0, 255 / 2, 255 / 2, 255 / 2);
//	}
//	else if (data->map[var->map_y][var->map_x] == 0)
//	{
//		color = mcolor(0, 255, 255, 0);
//		if (var->w_side == 1)
//			color = mcolor(0, 255 / 2, 255 / 2, 0);
//	}
//
//	int worldmap[24][24]=
//	{
//		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//		{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
//		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//		{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //ici a deux du bord
//		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
///		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//		{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //ou ici au milieux
//		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//	};
