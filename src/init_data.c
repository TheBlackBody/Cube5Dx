/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:23:39 by sfernand          #+#    #+#             */
/*   Updated: 2023/10/10 21:04:56 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void    init_data(char *path)
{
    int     fd;
    char    *line;
    t_data  data;

    fd = open(path, O_RDONLY);
    line = get_next_line(fd);
    while (line != NULL)
    {
        ft_printf("%s\n", line);
        if (strncmp("NO", line, 2) == 0)
        {
            data.NO = ft_strdup(line);
        }
        line = get_next_line(fd);
    }
    ft_printf("%s\n", data.NO);
    free (data.NO);
}