/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:23:39 by sfernand          #+#    #+#             */
/*   Updated: 2023/11/19 13:50:29 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	check_num(char	*n)
{
	int	i;

	i = 0;
	while (n[i])
	{
		if (n[i] < 48 || n[i] > 57)
			return (-1);
		i++;
	}
	return (0);
}

void	check_data(t_data *data)
{
	char	**f;
	char	**c;
	int		n_f;
	int		n_c;

	f = ft_split(data->F, ',');
	c = ft_split(data->C, ',');
	n_f = -1;
	n_c = -1;
	while (f[++n_f])
		check_data_utils(f, c, n_f, 100);
	while (c[++n_c])
		check_data_utils(f, c, 100, n_c);
	if (n_f != 3)
	{
		ft_printf("Error : F collors should be in RGB\n");
		ft_close();
	}
	if (n_c != 3)
	{
		ft_printf("Error : C collors should be in RGB\n");
		ft_close();
	}
	free(f);
	free(c);
}

void	initvalue(char **cdata, t_data *data, int i)
{
	init_no(cdata[i], data);
	init_so(cdata[i], data);
	init_we(cdata[i], data);
	init_ea(cdata[i], data);
}

void	init(char **cdata, t_data *data)
{
	int		i;
	int		n;

	i = 0;
	n = ft_strllen(cdata[i]);
	data->map = (char **)malloc(sizeof (char *) * (n * 100));
	n = 0;
	while (cdata[i])
	{
		if (i < 7)
		{
			initvalue(cdata, data, i);
		}
		else if (i >= 7 && (cdata[i][0] != '\n' && cdata[i]))
		{
			data->map[n] = ft_strdup(cdata[i]);
			n++;
		}
		free(cdata[i]);
		i++;
	}
	free(cdata[i]);
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
	free(line);
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
	init(cdata, data);
	utils_data(data);
	free (cdata);
}
