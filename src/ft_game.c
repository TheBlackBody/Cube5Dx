/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:49:33 by gpolve-g          #+#    #+#             */
/*   Updated: 2023/11/04 18:19:08 by gpolve-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"


	int worldmap[24][24]=
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //ici a deux du bord
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //ou ici au milieux
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
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
	(void)data;
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
		//	ft_printf("%c\n%i\n%i\n", data->map[var->map_y][var->map_x], var->map_x, var->map_y);
	//	if (data->map[var->map_y][var->map_x] == '1')
	//		var->is_hit = 1;
		if (worldmap[var->map_x][var->map_y] != 0)
			var->is_hit = 1;
		//	ft_printf("coucou\n");
	}
	if (var->w_side == 0)
		var->len_ray = var->side_dist_x - var->delt_dist_x;
	else
		var->len_ray = var->side_dist_y - var->delt_dist_y;
}

//t_data temp
static	void	ft_put_line(t_mlx *mlx, t_pose *var, int x, t_data *data)
{
	int	y;
	int	color;

(void)data;
	if (worldmap[var->map_x][var->map_y] == 1)
	{
		color = mcolor(0, 255, 0, 0);
		if (var->w_side == 1)
			color = mcolor(0, 255 / 2, 0, 0);
	}
	else if (worldmap[var->map_x][var->map_y] == 2)
	{
		color = mcolor(0, 0, 255, 0);
		if (var->w_side == 1)
			color = mcolor(0, 0, 255 / 2, 0);
	}
	else if (worldmap[var->map_x][var->map_y] == 3)
	{
		color = mcolor(0, 0, 0, 255);
		if (var->w_side == 1)
			color = mcolor(0, 0, 0, 255 / 2);
	}
	else if (worldmap[var->map_x][var->map_y] == 4)
	{
		color = mcolor(0, 255, 255, 255);
		if (var->w_side == 1)
			color = mcolor(0, 255 / 2, 255 / 2, 255 / 2);
	}
	else if (worldmap[var->map_x][var->map_y] == 0)
	{
		color = mcolor(0, 255, 255, 0);
		if (var->w_side == 1)
			color = mcolor(0, 255 / 2, 255 / 2, 0);
	}
	y = -1;
	//	color = color / 2;
	while (++y < mlx->size.s_y)
	{
		//	ft_printf("y = %i\n", y);
		if (y >= var->draw_start && y <= var->draw_end)
		{
		//	ft_printf("y = %i, oui\n", y);
			ft_pixel_put(mlx, x, y, color);
		}
		else
		{
		//	ft_printf("y = %i, non\n", y);
			//	ft_printf("non\n");
			ft_pixel_put(mlx, x, y, mcolor(0, 0, 0, 0));
		}
	}
}

//t_data temp
static	void	ft_line_height(t_mlx *mlx, t_pose *var, int x, t_data *data)
{
	int	line_height;

	line_height = (int)(mlx->size.s_y / var->len_ray);
	var->draw_start = -line_height / 2 + mlx->size.s_y / 2;
	if (var->draw_start < 0)
		var->draw_start = 0;
	var->draw_end = line_height / 2 + mlx->size.s_y / 2;//ca devrait etre end mais fonc pa
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

	var = mlx->var;
	if (keycode == 0)
	{
	if (!worldmap[(int)(var->x - var->dir_x * (var->move_speed + 0.2))][(int)var->y])
		var->x -= var->dir_y * var->move_speed;
	if (!worldmap[(int)var->x][(int)(var->y + var->dir_y * (var->move_speed + 0.2))])
		var->y += var->dir_x * var->move_speed;
	}
	if (keycode == 2)
	{
	if (!worldmap[(int)(var->x + var->dir_x * (var->move_speed + 0.2))][(int)var->y])
		var->x += var->dir_y * var->move_speed;
	if (!worldmap[(int)var->x][(int)(var->y - var->dir_y * (var->move_speed + 0.2))])
		var->y -= var->dir_x * var->move_speed;
	}
	ft_calc(mlx);
}

void	move_front(int keycode, t_mlx *mlx)
{
	t_pose *var;

	var = mlx->var;
	if (keycode == 13)
	{
	if (!worldmap[(int)(var->x + var->dir_x * (var->move_speed + 0.2))][(int)var->y])
		var->x += var->dir_x * var->move_speed;
	if (!worldmap[(int)var->x][(int)(var->y + var->dir_y * (var->move_speed + 0.2))])
		var->y += var->dir_y * var->move_speed;
	}
	if (keycode == 1)
	{
	if (!worldmap[(int)(var->x - var->dir_x * (var->move_speed * 1.2))][(int)var->y])
		var->x -= var->dir_x * var->move_speed;
	if (!worldmap[(int)var->x][(int)(var->y + var->dir_y * (var->move_speed + 0.2))])
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
	(void)mlx;
	ft_printf("x = %i, y = %i\n", x, y);
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
	mlx->var = &data->pose;
	mlx->data = data;
	mlx->var->x = 22;
	mlx->var->y = 12;
	ft_calculations(mlx, data);
//	mlx_key_hook(mlx->mlx_w, key_hook, mlx);
//	mlx_mouse_hook(mlx->mlx_w, mouse_hook, mlx);
	mlx_hook(mlx->mlx_w, 17, (1L << 19), ft_close_w, mlx);
	mlx_hook(mlx->mlx_w, 6, 0L, mouse_hook, mlx);
	mlx_hook(mlx->mlx_w, 2, 1L << 0, key_hook, mlx);
//	mlx_loop_hook(mlx, ft_calc, mlx);
	mlx_loop(mlx);
}
