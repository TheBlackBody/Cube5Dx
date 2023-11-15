/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:00:42 by sfernand          #+#    #+#             */
/*   Updated: 2023/11/15 13:50:25 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void    init_NO(char *line, t_data *data)
{
        if (strncmp("NO", line, 2) == 0)
                data->NO = ft_substr(line, 3, ft_strllen(line));
        if (strncmp("F", line, 1) == 0)
                data->F = ft_substr(line, 2, ft_strllen(line));
}

void    init_SO(char *line, t_data *data)
{
        if (strncmp("SO", line, 2) == 0)
                data->SO = ft_substr(line, 3, ft_strllen(line));
        if (strncmp("C", line, 1) == 0)
                data->C = ft_substr(line, 2, ft_strllen(line));
}

void    init_WE(char *line, t_data *data)
{
        if (strncmp("WE", line, 2) == 0)
                data->WE = ft_substr(line, 3, ft_strllen(line));
}

void    init_EA(char *line, t_data *data)
{
        if (strncmp("EA", line, 2) == 0)
                data->EA = ft_substr(line, 3, ft_strllen(line));
}