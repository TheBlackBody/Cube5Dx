/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:23:39 by sfernand          #+#    #+#             */
/*   Updated: 2023/11/09 21:22:32 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	init(char **cdata, t_data *data)
{
	int		i;
	int		n;

	i = 0;
	n = ft_strllen(cdata[i]);
	data->map = (char **)malloc(sizeof (char *) * (n * 100));
	n = 0;
	ft_printf("t2\n");
	while (cdata[i])
	{
		if (i < 7)
		{
			init_NO(cdata[i], data);
            init_SO(cdata[i], data);
            init_WE(cdata[i], data);
            init_EA(cdata[i], data);
		}
		else if (i >= 7 && (cdata[i][0] != '\n' && cdata[i]))
		{
			data->map[n] = ft_strdup(cdata[i]);
			n++;
		}
		i++;
	}
	data->map[n] = NULL;
}

void	init_data(char *path, t_data *data)
{
	char	**cdata;
	char	*line;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line[0] == '\n' && line)
		line = get_next_line(fd);
	i = ft_strllen(line);
	close(fd);
	cdata = (char **)malloc(sizeof (char *) * (i * 100));
	fd = open(path, O_RDONLY);
	i = 0;
	cdata[i] = get_next_line(fd);
	while (cdata[i])
	{
		i++;
		cdata[i] = get_next_line(fd);
	}
	close(fd);
	ft_printf("tt\n");
	init(cdata, data);
	i = 0;
	while (data->map[i] != NULL)
	{
		ft_printf("%s\n", data->map[i]);
		i++;
	}
	ft_printf("OK\n");
}