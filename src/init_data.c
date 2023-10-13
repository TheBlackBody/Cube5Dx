/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:23:39 by sfernand          #+#    #+#             */
/*   Updated: 2023/10/12 15:41:55 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

char    **init_data(char *path, t_data *data)
{
    int     fd;
    char    *line;
    int     i;
    int     a;
    char    **map;

    i = 0;
    a = 0;
    fd = open(path, O_RDONLY);
    line = get_next_line(fd);
    while (line != NULL)
    {
        ft_printf("test\n");
        ft_printf("%s\n", line);
        if (a < 7)
        {
            init_NO(line, data);
            init_SO(line, data);
            init_WE(line, data);
            init_EA(line, data);
            a++;
            ft_printf("%i\n", a);
        }
        else if (line[0] != '\n' && line)
        {
            ft_printf("enter\n");
            if (!map)
            {
                ft_printf("test\n");
                map = (char **)malloc(sizeof (char *) * (ft_strllen(line) * 100));
            }
            ft_printf("enter %i\n", ft_strllen(line));
            map[i] = ft_strdup(line);
            ft_printf("enter\n");
            ft_printf("%s\n", map[i]);
            i++;
        }
        ft_printf("cc\n");
        line = get_next_line(fd);
    }
    map[i] = NULL;
    close (fd);
    ft_printf("cc\n");
    return(map);
}