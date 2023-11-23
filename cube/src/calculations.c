/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 02:39:09 by gpolve-g          #+#    #+#             */
/*   Updated: 2023/11/23 17:32:04 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_calcul_delt(t_pose *var)
{
	var->delt_dist_x = 1e30;
	if (var->ray_dir_x != 0)
		var->delt_dist_x = ft_abs(1 / var->ray_dir_x);
	var->delt_dist_y = 1e30;
	if (var->ray_dir_y != 0)
		var->delt_dist_y = ft_abs(1 / var->ray_dir_y);
}

void	ft_calcul_step(t_pose *var)
{
	if (var->ray_dir_x < 0)
	{
		var->step_x = -1;
		var->side_dist_x = (var->x - var->map_x) * var->delt_dist_x;
	}
	else
	{
		var->step_x = 1;
		var->side_dist_x = (var->map_x + 1 - var->x) * var->delt_dist_x;
	}
	if (var->ray_dir_y < 0)
	{
		var->step_y = -1;
		var->side_dist_y = (var->y - var->map_y) * var->delt_dist_y;
	}
	else
	{
		var->step_y = 1;
		var->side_dist_y = (var->map_y + 1 - var->y) * var->delt_dist_y;
	}
}

void	ft_dda(t_pose *var, t_data *data)
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
