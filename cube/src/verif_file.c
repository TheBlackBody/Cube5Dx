/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:47:46 by sfernand          #+#    #+#             */
/*   Updated: 2023/11/23 17:33:44 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	lenx(char **map, int y)
{
	int	x;

	x = 0;
	while (map[y][x] != 0)
	{
		x++;
	}
	return (x);
}

int	leny(char **map)
{
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		y++;
	}
	return (y);
}

char	**dup_map(char **map)
{
	int		y;
	char	**temp;

	y = 0;
	temp = (char **)malloc(sizeof (char *) * (lenx(map, y) * 100));
	while (map[y] != NULL)
	{
		temp[y] = ft_strdup(map[y]);
		y++;
	}
	temp[y] = NULL;
	return (temp);
}

void	flood_fill(char **map, int x, int y)
{
	if (y - 1 < -1 || (y + 1 == leny(map) && map[y][x] != '1')
		|| (x - 1 == lenx(map, y) && map[y][x] != '1') || map[y][x] == ' ')
	{
		ft_printf("Error : The map should be closed\n");
		ft_close();
	}
	if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'E'
			&& map[y][x] != 'W' && map[y][x] != 'N' && map[y][x] != 'S')
	{
		ft_printf("Error: the char '%c' was not supported\n", map[y][x]);
		ft_close();
	}
	else if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'W'
			|| map[y][x] == 'S' || map[y][x] == 'E')
	{
		if (map[y][x + 1] == '\0' || x - 1 == -1
			|| map[y][x + 1] == '\n' || map[y][x - 1] == '\n'
			|| map[y + 1][x] == '\n' || map[y - 1][x] == '\n')
		{
			ft_printf("Error : The map should be closed\n");
			ft_close();
		}
		map[y][x] = '1';
		flood_fill2(map, x, y);
	}
}

void	verif_map(t_data *data)
{
	int		x;
	int		y;
	int		i;
	char	**map;

	x = 0;
	y = 0;
	i = ft_strlen(data->map[y]);
	map = dup_map(data->map);
	while (x != i && (map[y][x] != 'N' && map[y][x] != 'E'
			&& map[y][x] != 'S' && map[y][x] != 'W'))
	{
		x++;
		i = ft_strlen(map[y]);
		if (x == i)
		{
			x = 0;
			y++;
		}
		check_char(map, x, y);
	}
	data->pose.x = x;
	data->pose.y = y;
	flood_fill(map, x, y);
	free_map(map);
}
