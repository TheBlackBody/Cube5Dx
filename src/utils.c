/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:13:44 by gpolve-g          #+#    #+#             */
/*   Updated: 2023/11/21 16:11:49 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_close_void(void)
{
	ft_printf("Error: your map is empty\n");
	exit(0);
}

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
	free(data->no);
	free(data->so);
	free(data->we);
	free(data->ea);
	free(data->f);
	free(data->c);
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
