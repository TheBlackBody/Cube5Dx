/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:17:40 by sfernand          #+#    #+#             */
/*   Updated: 2023/11/17 16:27:03 by gpolve-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void    ft_close(void)
{
	exit(0);
}

void	ft_ignit_sprite(t_data *data, t_mlx *mlx)
{
	data->north.referenc = mlx_xpm_file_to_image(mlx->mlx, data->NO ,&data->north.size.x, &data->north.size.y);
//	ft_printf("\ndata NO = \n%s\n", data->NO);
//	ft_printf("\ndata size north y = \n%i\n", data->north.size.y);
	data->north.pixels = mlx_get_data_addr(data->north.referenc, &data->north.bits_per_pixel, &data->north.line_size, &data->north.endian);
	data->south.referenc = mlx_xpm_file_to_image(mlx->mlx, data->SO ,&data->south.size.x, &data->south.size.y);
//      ft_printf("\ndata SO = \n%s\n", data->SO);
	data->south.pixels = mlx_get_data_addr(data->south.referenc, &data->south.bits_per_pixel, &data->south.line_size, &data->south.endian);
	data->west.referenc = mlx_xpm_file_to_image(mlx->mlx, data->WE ,&data->west.size.x, &data->west.size.y);
//      ft_printf("\ndata WE = \n%s\n", data->WE);
	data->west.pixels = mlx_get_data_addr(data->west.referenc, &data->west.bits_per_pixel, &data->west.line_size, &data->west.endian);
      data->east.referenc = mlx_xpm_file_to_image(mlx->mlx, data->EA ,&data->east.size.x, &data->east.size.y);
//      ft_printf("\ndata EA = \n%s\n", data->EA);
	data->east.pixels = mlx_get_data_addr(data->east.referenc, &data->east.bits_per_pixel, &data->east.line_size, &data->east.endian);
	data->pose.text_width = 32;
	data->pose.text_height = 32;
//(void)mlx;
//(void)data;
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
	data->pose.move_speed = 0.15;
	data->pose.rot_speed = 0.07;
	mlx->data = data;
	data->pose.mouse_x = -2147483648;
	data->pose.mouse_y = -2147483648;
	ft_ignit_sprite(data, mlx);
//	char **temp;
//	int	i;

//	i = -1;
//	if (!data->F)
	//	mlx->field = mcolor(0, 139, 69, 19);
//	else
//	{
//		temp = ft_split(data->F, ',');
//		mlx->field = mcolor(0, ft_atoi(temp[0]), ft_atoi(temp[1]), ft_atoi(temp[2]));
	
	//	while(++temp)
	//		free(*temp);
	//	free(temp);
//	}
//	if (!data->C)
	//	mlx->field = mcolor(0, 0, 0, 190);
//	else
//	{
//		temp = ft_split(data->C, ',');
//		mlx->sky = mcolor(0, ft_atoi(temp[0]), ft_atoi(temp[1]), ft_atoi(temp[2]));
//	
//		while(++temp)
//			free(*temp);
//		free(temp);
//	}
}

int main(int argc, char **argv)
{
	t_data	data;
	t_mlx	mlx;
	int		i;

	i = 0;
	if (argc == 2)
	{
		parse_path(argv[1], 1);
		init_data(argv[1], &data);
		while (data.map[i] != NULL)
		{
			ft_printf("%s\n", data.map[i]);
			i++;
		}
		verif_map(&data);
		def_everything(&mlx, &data);
		ft_game(&mlx, &data);
	}
	else if (argc > 2) 
		ft_printf("Error : to many argument\n");
	else if (argc < 2) 
		ft_printf("Error : to less argument\n");
	return(0);
}
