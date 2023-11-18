/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolve-g <gpolve-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:11:44 by gpolve-g          #+#    #+#             */
/*   Updated: 2023/11/18 01:27:42 by gpolve-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

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
//	ft_printf("x = %i, y = %i\n", x, y);
	return (0);
}
