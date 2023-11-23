/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:03:40 by gpolve-g          #+#    #+#             */
/*   Updated: 2023/11/23 17:32:49 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	move_left(int keycode, t_mlx *mlx)
{
	t_pose	*var;
	t_data	*data;

	data = mlx->data;
	var = mlx->var;
	if (keycode == 2)
	{
		if (data->map[(int)var->y][(int)(var->x - var->dir_y
			* (var->move_speed * 1.2))] != '1')
			var->x -= var->dir_y * var->move_speed;
		if (data->map[(int)(var->y + var->dir_x * (var->move_speed
					* 1.2))][(int)var->x] != '1')
			var->y += var->dir_x * var->move_speed;
	}
	if (keycode == 0)
	{
		if (data->map[(int)var->y][(int)(var->x + var->dir_y
			* (var->move_speed * 1.2))] != '1')
			var->x += var->dir_y * var->move_speed;
		if (data->map[(int)(var->y - var->dir_x * (var->move_speed
					* 1.2))][(int)var->x] != '1')
			var->y -= var->dir_x * var->move_speed;
	}
	ft_calc(mlx);
}

void	move_front(int keycode, t_mlx *mlx)
{
	t_pose	*var;
	t_data	*data;

	data = mlx->data;
	var = mlx->var;
	if (keycode == 13)
	{
		if (data->map[(int)var->y][(int)(var->x + var->dir_x
			* (var->move_speed * 1.2))] != '1')
			var->x += var->dir_x * var->move_speed;
		if (data->map[(int)(var->y + var->dir_y
				* (var->move_speed * 1.2))][(int)var->x] != '1')
			var->y += var->dir_y * var->move_speed;
	}
	if (keycode == 1)
	{
		if (data->map[(int)var->y][(int)(var->x - var->dir_x
			* (var->move_speed * 1.2))] != '1')
			var->x -= var->dir_x * var->move_speed;
		if (data->map[(int)(var->y - var->dir_y
				* (var->move_speed * 1.2))][(int)var->x] != '1')
			var->y -= var->dir_y * var->move_speed;
	}
	ft_calc(mlx);
}

void	rotat_right(t_mlx *mlx)
{
	double	oldir_x;
	double	old_plane;
	t_pose	*var;

	var = mlx->var;
	oldir_x = var->dir_x;
	old_plane = var->plane_x;
	var->dir_x = var->dir_x * cos(-var->rot_speed)
		- var->dir_y * sin(-var->rot_speed);
	var->dir_y = oldir_x * sin(-var->rot_speed) + var->dir_y
		* cos(-var->rot_speed);
	var->plane_x = var->plane_x * cos(-var->rot_speed)
		- var->plane_y * sin(-var->rot_speed);
	var->plane_y = old_plane * sin(-var->rot_speed)
		+ var->plane_y * cos(-var->rot_speed);
	ft_calc(mlx);
}

void	rotat_left(t_mlx *mlx)
{
	double	oldir_x;
	double	old_plane;
	t_pose	*var;

	var = mlx->var;
	oldir_x = var->dir_x;
	old_plane = var->plane_x;
	var->dir_x = var->dir_x * cos(var->rot_speed)
		- var->dir_y * sin(var->rot_speed);
	var->dir_y = oldir_x * sin(var->rot_speed) + var->dir_y
		* cos(var->rot_speed);
	var->plane_x = var->plane_x * cos(var->rot_speed)
		- var->plane_y * sin(var->rot_speed);
	var->plane_y = old_plane * sin(var->rot_speed)
		+ var->plane_y * cos(var->rot_speed);
	ft_calc(mlx);
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
