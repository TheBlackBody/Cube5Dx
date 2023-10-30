/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:17:40 by sfernand          #+#    #+#             */
/*   Updated: 2023/10/24 16:47:55 by gpolve-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void    ft_close(void)
{
	exit(0);
}

static void	def_everything(t_mlx *mlx, t_data *data)
{
	mlx->size.s_x = 640;
	mlx->size.s_y = 480;
	mlx->mlx = mlx_init();
	mlx->mlx_w = mlx_new_window(mlx->mlx,mlx->size.s_x,
			mlx->size.s_y,"test");
	mlx->img = mlx_new_image(mlx->mlx, mlx->size.s_x,
			mlx->size.s_y);
	mlx->addr = mlx_get_data_addr(mlx->img,
			&mlx->bits_per_pixel, &mlx->line_lenght,
			&mlx->endian);
	data->pose.dir_x = -1;
	data->pose.dir_y = 0;
	data->pose.plane_x = 0;
	data->pose.plane_y = 0.66;
	data->pose.cur_time = 0;
	data->pose.prev_time = 0;
}

int main(int argc, char **argv)
{
	t_data	data;
	t_lmx	mlx;
	int		i;

	i = -1;
	if (argc == 2)
	{
		parse_path(argv[1]);
		data.map = init_data(argv[1], &data);
		while (data.map[i++] != NULL)
			ft_printf("%s\n", data.map[i]);
		verif_map(&data);
	}
	else if (argc > 2) 
		ft_printf("Error : to many argument\n");
	else if (argc < 2) 
		ft_printf("Error : to less argument\n");
	def_everything(&mlx, &data);
	ft_game(&mlx, &data);
	return(0);
}
