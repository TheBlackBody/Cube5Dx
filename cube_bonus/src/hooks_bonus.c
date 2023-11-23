/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:11:44 by gpolve-g          #+#    #+#             */
/*   Updated: 2023/11/23 17:24:40 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		ft_close_w(mlx);
	else if (keycode == 0 || keycode == 2)
		move_left(keycode, mlx);
	else if (keycode == 13 || keycode == 1)
		move_front(keycode, mlx);
	else if (keycode == 124)
		rotat_left(mlx);
	else if (keycode == 123)
		rotat_right(mlx);
	return (0);
}

int	mouse_hook(int x, int y, t_mlx *mlx)
{
	t_pose	*var;

	var = mlx->var;
	if (var->mouse_x == -2147483648 && var->mouse_y == -2147483648)
	{
		var->mouse_x = x;
		var->mouse_y = y;
		return (0);
	}
	if (var->mouse_x > x)
	{
		var->mouse_x = x;
		rotat_right(mlx);
	}
	else if (var->mouse_x < x)
	{
		var->mouse_x = x;
		rotat_left(mlx);
	}
	return (0);
}
