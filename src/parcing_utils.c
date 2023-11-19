/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:02:04 by sfernand          #+#    #+#             */
/*   Updated: 2023/11/19 15:37:42 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	flood_fill2(char **map, int x, int y)
{
	if (y != -1)
		flood_fill(map, x, y - 1);
	if (y != leny(map))
		flood_fill(map, x, y + 1);
	if (x != -1)
		flood_fill(map, x - 1, y);
	if (x != lenx(map, y))
		flood_fill(map, x + 1, y);
}

void	check_char(char **map, int x, int y)
{
	if (map[y] == NULL && (map[y][x] != 'N' || map[y][x] != 'E'
		|| map[y][x] != 'S' || map[y][x] != 'W' || map[y][x] != '0'
		|| map[y][x] != '1' || map[y][x] != ' ' || map[y][x] != '\n'))
	{
		if (map[y][x] != 'N' || map[y][x] != 'E' || map[y][x] != 'S'
			|| map[y][x] != 'W' || map[y][x] != '0' || map[y][x] != '1'
			|| map[y][x] != ' ' || map[y][x] != '\n')
		{
			ft_printf("Error : the map should only contain char");
			ft_printf("'N' 'E' 'W' 'S' '0' '1'\n");
		}
		else
		{
			ft_printf("Error : the map should contain char");
			ft_printf("'N' 'E' 'W' 'S'\n");
		}
		ft_close();
	}
}

void	free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		free(map[y]);
		y++;
	}
	free(map);
}

void	utils_data(t_data *data)
{
	check_data(data);
	parse_path(data->NO, 2);
	parse_path(data->SO, 2);
	parse_path(data->EA, 2);
	parse_path(data->WE, 2);
}

void	check_data_utils(char **f, char **c, int n_f, int n_c)
{
	if (n_c == 100)
	{
		if (check_num(f[n_f]) == -1)
		{
			ft_printf("Error : F collors should be in integer\n%s\n", f[n_f]);
			ft_close();
		}
		free(f[n_f]);
	}
	else if (n_f == 100)
	{
		if (check_num(c[n_c]) == -1)
		{
			ft_printf("Error : C collors should be in integer\n");
			ft_close();
		}
		free(c[n_c]);
	}
}
