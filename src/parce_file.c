/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:07:53 by sfernand          #+#    #+#             */
/*   Updated: 2023/11/23 12:07:36 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	check_i(int i)
{
	if (i < 9)
	{
		ft_printf("Error : data incomplete\n");
		ft_close();
	}
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
	while (line && line[0] == '\n')
	{
		line = get_next_line(fd);
		if (line == NULL)
			ft_close_void();
	}
	while (line != NULL)
	{
		while (line && line[0] == '\n')
			line = get_next_line(fd);
		i++;
		line = get_next_line(fd);
	}
	check_i(i);
	free(line);
}
