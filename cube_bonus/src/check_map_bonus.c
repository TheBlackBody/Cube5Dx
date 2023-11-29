/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:41:33 by sfernand          #+#    #+#             */
/*   Updated: 2023/11/29 17:24:06 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

void	init_player(int x, int y, t_data *data)
{
	data->pose.x = x;
	data->pose.y = y;
}

void	check_malloc_error(char **map)
{
	if (!map)
	{
		ft_printf("Malloc error\n");
		ft_close();
	}
}

void	check_a(int a)
{
	if (a > 1)
	{
		ft_printf("Error : map shold containt only one N E W S\n");
		ft_close();
	}
}

void	check_map(t_data *data)
{
	int	x;
	int	y;
	int	i;
	int	a;

	x = 0;
	y = 0;
	i = ft_strlen(data->map[y]);
	a = 0;
	while (x != i && data->map[y] != NULL)
	{
		x++;
		i = ft_strlen(data->map[y]);
		if (x == i && data->map[y + 1] != NULL)
		{
			x = 0;
			y++;
		}
		if (data->map[y][x] == 'N' || data->map[y][x] == 'E'
			|| data->map[y][x] == 'S' || data->map[y][x] == 'W')
			a++;
		check_a(a);
	}
}
