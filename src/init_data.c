/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:23:39 by sfernand          #+#    #+#             */
/*   Updated: 2023/11/15 15:47:24 by sfernand         ###   ########.fr       */
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
	char	**F;
	char	**C;
	int		n_F;
	int		n_C;

	F = ft_split(data->F, ',');
	C = ft_split(data->C, ',');
	n_F = -1;
	n_C = -1;
	while (F[++n_F])
	{
		if (check_num(F[n_F]) == -1)
		{
			ft_printf("Error : F collors should be in integer\n%s\n", F[n_F]);
			ft_close();
		}
		free(F[n_F]);
	}
	while (C[++n_C])
	{
		if (check_num(C[n_C]) == -1)
		{
			ft_printf("Error : C collors should be in integer\n");
			ft_close();
		}
		free(C[n_C]);
	}
	if (n_F != 3)
	{
		ft_printf("Error : F collors should be in RGB\n");
		ft_close();
	}
	if (n_C != 3)
	{
		ft_printf("Error : C collors should be in RGB\n");
		ft_close();
	}
	free(F);
	free(C);
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
	ft_printf("tt\n");
	init(cdata, data);
	i = 0;
	check_data(data);
	parse_path(data->NO, 2);
	parse_path(data->SO, 2);
	parse_path(data->EA, 2);
	parse_path(data->WE, 2);
	while (data->map[i] != NULL)
	{
		ft_printf("%s\n", data->map[i]);
		i++;
	}
	ft_printf("OK\n");
	free (cdata);
}