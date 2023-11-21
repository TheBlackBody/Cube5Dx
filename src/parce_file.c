/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:07:53 by sfernand          #+#    #+#             */
/*   Updated: 2023/11/21 18:57:07 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

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
	while (line[0] == '\n' && line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			ft_close_void();
	}
	while (line != NULL)
	{
		while (line[0] == '\n' && line)
			line = get_next_line(fd);
		i++;
		line = get_next_line(fd);
	}
	if (i < 10)
	{
		ft_printf("Error : data incomplete\n");
		ft_close();
	}
}
