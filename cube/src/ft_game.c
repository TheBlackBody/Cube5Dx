/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:49:33 by gpolve-g          #+#    #+#             */
/*   Updated: 2023/11/23 17:32:25 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_calculations(t_mlx *mlx, t_data *data)
{
	int		x;
	t_pose	var;

	var = *mlx->var;
	x = -1;
	while (++x < mlx->size.s_x)
	{
		var.camera_x = 2 * x / (double)mlx->size.s_x - 1;
		var.ray_dir_x = var.dir_x + var.plane_x * var.camera_x;
		var.ray_dir_y = var.dir_y + var.plane_y * var.camera_x;
		var.map_x = (int)var.x;
		var.map_y = (int)var.y;
		ft_calcul_delt(&var);
		var.is_hit = 0;
		ft_calcul_step(&var);
		ft_dda(&var, data);
		ft_line_height(mlx, &var, x, data);
	}
	put_image(mlx);
}

void	ft_game(t_mlx *mlx, t_data *data)
{
	mlx->var = &data->pose;
	ft_calculations(mlx, mlx->data);
	mlx_hook(mlx->mlx_w, 17, (1L << 19), ft_close_w, mlx);
	mlx_hook(mlx->mlx_w, 6, 0L, mouse_hook, mlx);
	mlx_hook(mlx->mlx_w, 2, 1L << 0, key_hook, mlx);
	mlx_loop(mlx->mlx);
}
