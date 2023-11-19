/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:41:33 by sfernand          #+#    #+#             */
/*   Updated: 2023/11/19 14:57:00 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	check_a(int a)
{
	if (a > 1)
	{
		ft_printf("Error : map shold containt only one N E W S");
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
