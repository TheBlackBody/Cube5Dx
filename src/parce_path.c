/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:39:54 by sfernand          #+#    #+#             */
/*   Updated: 2023/10/10 20:40:52 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	veriffile(char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd == 3)
	{
		ft_printf("Error: your map is a directory\n");
		close(fd);
		ft_close();
	}
	close(fd);
	fd = open(path, O_RDONLY);
	ft_printf("%i\n", fd);
	if (fd != 3)
	{
		ft_printf("Error: your map doesn't exist\n");
		close(fd);
		ft_close();
	}
	close(fd);
}

void	verifname(char *path, int i, int n, char *extention)
{
	while (path[i++] != '\0' && n < 3)
	{
		if (path[i] != extention[n])
		{
			ft_printf("Error02: your map name does have extention <.cube>\n");
			ft_close();
		}
		n++;
	}
}

void    parse_path(char *path)
{
    int		i;
	int		n;
	char	*extention;

	i = 0;
	n = 0;
	extention = "cube";
	while (path[i + 1] != '.')
	{
		if (path[i] == '\0')
		{
			ft_printf("Error01: your map name does have <.> ");
			ft_printf("+ extention <cube>\n");
			ft_close();
		}
		i++;
	}
	i++;
	verifname(path, i, n, extention);
	veriffile(path);
}