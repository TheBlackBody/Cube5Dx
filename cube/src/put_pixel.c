/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:17:52 by gpolve-g          #+#    #+#             */
/*   Updated: 2023/11/23 17:33:17 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_lenght
			+ x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_image(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_w, mlx->img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->img);
}

int	mcolor(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
