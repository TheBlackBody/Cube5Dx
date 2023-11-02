/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:49:33 by gpolve-g          #+#    #+#             */
/*   Updated: 2023/10/31 12:10:20 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"


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
		var->side_dist_x = (var->ig_x - var->map_x) * var->delt_dist_x; //j'ai reverif et c'est bien ca, ce qui fait 0 mais bon;
	}
	else
	{
		var->step_x = 1;
		var->side_dist_x = (var->map_x + 1 - var->ig_x) * var->delt_dist_x; //toujours
	}
	if (var->ray_dir_y < 0)
	{
		var->step_y = -1;
		var->side_dist_y = (var->ig_y - var->map_y) * var->delt_dist_y;
	}
	else
	{
		var->step_y = 1;
		var->side_dist_y = (var->map_y + 1 - var->ig_y) * var->delt_dist_y; //toujours
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
		ft_printf("%c\n%i\n%i\n", data->map[var->map_y][var->map_x], var->map_x, var->map_y);
		if (data->map[var->map_y][var->map_x] == '1')
			var->is_hit = 1;
	}
	if (var->w_side == 0)
		var->len_ray = var->side_dist_x - var->delt_dist_x;
	else
		var->len_ray = var->side_dist_y - var->delt_dist_y;
}

static	void	ft_put_line(t_mlx *mlx, t_pose *var, int x)
{
	int	y;
	int	color;

	color = mcolor(0, 255, 0, 0);
	y = -1;
	if (var->w_side == 1)
		color = color / 2;
	while (++y <= mlx->size.s_y)
	{
		if (y <= var->draw_start && y >= var->draw_end)
			ft_pixel_put(mlx, x, y, color);
		else
			ft_pixel_put(mlx, x, y, mcolor(0, 0, 0, 0));
	}
}
static	void	ft_line_height(t_mlx *mlx, t_pose *var, int x)
{
	int	line_height;

	line_height = (int)(mlx->size.s_y / var->len_ray);
	var->draw_start = -line_height / 2 + mlx->size.s_y / 2;
	if (var->draw_start < 0)
		var->draw_start = 0;
	var->draw_start = line_height / 2 + mlx->size.s_y / 2;
	if (var->draw_start >= mlx->size.s_y)
		var->draw_start = mlx->size.s_y - 1;
	ft_put_line(mlx, var, x);
}

static	void	ft_calculations(t_mlx *mlx, t_data *data)
{
	int	x;
	t_pose	var; //avant c'etait un pointeur;

	var = data->pose;
	x = -1;
	while (++x < mlx->size.s_x)
	{
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
		ft_line_height(mlx, &var, x);

	}
//	return ;
}

void	ft_game(t_mlx *mlx, t_data *data)
{
	ft_printf("%p\n", mlx->mlx);
	ft_calculations(mlx, data);
}
