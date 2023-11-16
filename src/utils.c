/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolve-g <gpolve-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:13:44 by gpolve-g          #+#    #+#             */
/*   Updated: 2023/11/16 15:14:24 by gpolve-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

double	ft_abs(double val)
{
	if (val < 0)
		val = val * -1;
	return (val);
}

int	ft_close_w(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_w);
	exit(0);
	return (0);
}
