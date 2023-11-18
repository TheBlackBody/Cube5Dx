/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolve-g <gpolve-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:13:44 by gpolve-g          #+#    #+#             */
/*   Updated: 2023/11/18 04:07:04 by gpolve-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

double	ft_abs(double val)
{
	if (val < 0)
		val = val * -1;
	return (val);
}

static int	ft_big_free(char **str)
{
	int	i;

	i = -1;
	if (!str)
		return (1);
	while (str[++i])
		free(str[i]);
	free(str);
	return (0);
}

static void	ft_free_data(t_data *data, t_mlx *mlx)
{
	free(data->NO);
	free(data->SO);
	free(data->WE);
	free(data->EA);
	free(data->F);
	free(data->C);
	mlx_destroy_image(mlx->mlx, data->north.referenc);
	mlx_destroy_image(mlx->mlx, data->south.referenc);
	mlx_destroy_image(mlx->mlx, data->west.referenc);
	mlx_destroy_image(mlx->mlx, data->east.referenc);
}

int	ft_close_w(t_mlx *mlx)
{
	if (ft_big_free(mlx->var->f) || ft_big_free(mlx->var->c)
		|| ft_big_free(mlx->data->map))
		ft_printf("Error while freeing\n");
	ft_free_data(mlx->data, mlx);
	mlx_destroy_window(mlx->mlx, mlx->mlx_w);
	exit(0);
	return (0);
}
