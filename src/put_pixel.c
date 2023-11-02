/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolve-g <gpolve-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:17:52 by gpolve-g          #+#    #+#             */
/*   Updated: 2023/11/02 11:56:54 by gpolve-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

//	if (mlx->graph->x < mlx->size->s_x && mlx->graph->y < mlx->size->s_y)
//	{
		dst = mlx->addr + (y * mlx->line_lenght
				+ x * (mlx->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
//	}
}

/*void	pixel_color(t_coor graph, t_mlx *mlx)
{
	if (graph.i == (int)graph.ite_max && graph.color != 22)
		ft_pixel_put(mlx, graph.x, graph.y,
			mcolor(0, vabs((255 - (int)graph.x)),
				255 - vabs((255 - (int)graph.y)),
				255 - vabs((255 - (int)graph.x))));
	else if (graph.i == (int)graph.ite_max && graph.color == 22)
		ft_pixel_put(mlx, graph.x, graph.y, mcolor(0, 0, 0, 0));
	else
		ft_pixel_put(mlx, graph.x, graph.y, color_change(&graph));
}*/

void	put_image(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_w, mlx->img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->img);
}

int	mcolor(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

