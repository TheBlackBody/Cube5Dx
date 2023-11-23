/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:17:40 by sfernand          #+#    #+#             */
/*   Updated: 2023/11/23 11:33:16 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_close(void)
{
	exit(0);
}

void	ft_ignit_sprite(t_data *data, t_mlx *mlx)
{
	data->north.referenc = mlx_xpm_file_to_image(mlx->mlx, data->no,
			&data->north.size.s_x, &data->north.size.s_y);
	data->north.pixels = mlx_get_data_addr(data->north.referenc,
			&data->north.bits_per_pixel,
			&data->north.line_size, &data->north.endian);
	data->south.referenc = mlx_xpm_file_to_image(mlx->mlx, data->so,
			&data->south.size.s_x, &data->south.size.s_y);
	data->south.pixels = mlx_get_data_addr(data->south.referenc,
			&data->south.bits_per_pixel, &data->south.line_size,
			&data->south.endian);
	data->west.referenc = mlx_xpm_file_to_image(mlx->mlx, data->we,
			&data->west.size.s_x, &data->west.size.s_y);
	data->west.pixels = mlx_get_data_addr(data->west.referenc,
			&data->west.bits_per_pixel, &data->west.line_size,
			&data->west.endian);
	data->east.referenc = mlx_xpm_file_to_image(mlx->mlx, data->ea,
			&data->east.size.s_x, &data->east.size.s_y);
	data->east.pixels = mlx_get_data_addr(data->east.referenc,
			&data->east.bits_per_pixel, &data->east.line_size,
			&data->east.endian);
	data->pose.text_width = 64;
	data->pose.text_height = 64;
}

static void	ft_ignit_fc(t_pose *var, t_data *data)
{
	var->f = ft_split(data->f, ',');
	var->c = ft_split(data->c, ',');
}

static void	def_everything(t_mlx *mlx, t_data *data)
{
	mlx->size.s_x = 640;
	mlx->size.s_y = 480;
	mlx->mlx = mlx_init();
	mlx->mlx_w = mlx_new_window(mlx->mlx, mlx->size.s_x,
			mlx->size.s_y, "Cub5DX");
	mlx->img = mlx_new_image(mlx->mlx, mlx->size.s_x,
			mlx->size.s_y);
	mlx->addr = mlx_get_data_addr(mlx->img,
			&mlx->bits_per_pixel, &mlx->line_lenght,
			&mlx->endian);
	data->pose.dir_x = -1;
	data->pose.dir_y = 0;
	data->pose.plane_x = 0;
	data->pose.plane_y = 0.66;
	data->pose.move_speed = 0.15;
	data->pose.rot_speed = 0.07;
	mlx->data = data;
	data->pose.mouse_x = -2147483648;
	data->pose.mouse_y = -2147483648;
	ft_ignit_sprite(data, mlx);
	ft_ignit_fc(&data->pose, data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_mlx	mlx;

	data.no = ft_calloc(1, 1);
	data.so = ft_calloc(1, 1);
	data.ea = ft_calloc(1, 1);
	data.we = ft_calloc(1, 1);
	data.c = ft_calloc(1, 1);
	data.f = ft_calloc(1, 1);
	if (argc == 2)
	{
		parse_path(argv[1], 1);
		parce_file(argv[1]);
		init_data(argv[1], &data);
		verif_map(&data);
		check_map(&data);
		def_everything(&mlx, &data);
		ft_game(&mlx, &data);
	}
	else if (argc > 2)
		ft_printf("Error : to many argument\n");
	else if (argc < 2)
		ft_printf("Error : to less argument\n");
	return (0);
}
