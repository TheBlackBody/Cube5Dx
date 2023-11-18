/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolve-g <gpolve-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:11:44 by gpolve-g          #+#    #+#             */
/*   Updated: 2023/11/18 02:19:32 by gpolve-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		ft_close_w(mlx);
	else if (keycode == 0 || keycode == 2)
		move_left(keycode, mlx);
	else if (keycode == 13 || keycode == 1)
		move_front(keycode, mlx);
	else if (keycode == 123)
		rotat_left(mlx);
	else if (keycode == 124)
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
