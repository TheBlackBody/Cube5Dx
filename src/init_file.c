/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:00:42 by sfernand          #+#    #+#             */
/*   Updated: 2023/11/18 23:09:09 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	init_no(char *line, t_data *data)
{
	if (strncmp("NO", line, 2) == 0)
		data->NO = ft_substr(line, 3, ft_strllen(line));
	if (strncmp("F", line, 1) == 0)
		data->F = ft_substr(line, 2, ft_strllen(line));
}

void	init_so(char *line, t_data *data)
{
	if (strncmp("SO", line, 2) == 0)
		data->SO = ft_substr(line, 3, ft_strllen(line));
	if (strncmp("C", line, 1) == 0)
		data->C = ft_substr(line, 2, ft_strllen(line));
}

void	init_we(char *line, t_data *data)
{
	if (strncmp("WE", line, 2) == 0)
		data->WE = ft_substr(line, 3, ft_strllen(line));
}

void	init_ea(char *line, t_data *data)
{
	if (strncmp("EA", line, 2) == 0)
		data->EA = ft_substr(line, 3, ft_strllen(line));
}
