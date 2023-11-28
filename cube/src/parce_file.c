/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:07:53 by sfernand          #+#    #+#             */
/*   Updated: 2023/11/28 15:14:25 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	check_i(int i)
{
	if (i < 9)
	{
		ft_printf("Error : data incomplete %i\n", i);
		ft_close();
	}
}

char	*check_new_line(char *line, int fd)
{
	if (line && line[0] == '\n')
	{
		while (line && line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			if (line == NULL)
				ft_close_void();
		}
	}
	return (line);
}

void	parce_file(char *path)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		ft_close_void();
	line = check_new_line(line, fd);
	while (line != NULL)
	{
		while (line && line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
	check_i(i);
	free(line);
}
