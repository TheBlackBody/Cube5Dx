/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:39:54 by sfernand          #+#    #+#             */
/*   Updated: 2023/11/21 23:27:31 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	veriffile(char *path, int time)
{
	int		fd;
	char	*type;

	if (time == 1)
		type = "map";
	else if (time > 1)
		type = "texture";
	fd = open(path, O_DIRECTORY);
	if (fd == 3)
	{
		ft_printf("Error: your %s is a directory\n", type);
		close(fd);
		ft_close();
	}
	close(fd);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: your %s doesn't exist : '%s'\n", type, path);
		close(fd);
		ft_close();
	}
	close(fd);
}

void	verifname(char *path, int i, int n, char *extention)
{
	while (path[i++] != '\0' && n < ((int)ft_strllen(extention) - 1))
	{
		if (path[i] != extention[n])
		{
			ft_printf("Error: your map or your texture name does have");
			ft_printf(" extention <.cube> or <.xpm> if is texture\n");
			ft_close();
		}
		n++;
	}
	if (path[i] != extention[n])
	{
		ft_printf("Error: your map or your texture name does have");
		ft_printf(" extention <.cube> or <.xpm> if is texture\n");
		ft_close();
	}
}

void	ft_error(void)
{
	ft_printf("Error: your map name does have <.> ");
	ft_printf("+ extention <cube> or <xpm> if is texture\n");
	ft_close();
}

void	parse_path(char *path, int time)
{
	int		i;
	int		n;
	char	*extention;

	i = 0;
	n = 0;
	if (time == 1)
		extention = "cube";
	else if (time > 1)
		extention = "xpm";
	if (path == NULL)
			ft_error();
	while (path[i + 1] != '.')
	{
		if (path[i] == '\0')
			ft_error();
		i++;
	}
	i++;
	verifname(path, i, n, extention);
	veriffile(path, time);
}
