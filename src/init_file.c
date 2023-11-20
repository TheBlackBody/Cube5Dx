/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:00:42 by sfernand          #+#    #+#             */
/*   Updated: 2023/11/20 16:51:59 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	init_no(char *line, t_data *data)
{
	if (strncmp("NO", line, 2) == 0)
		data->no = ft_substr(line, 3, ft_strllen(line));
	if (strncmp("F", line, 1) == 0)
		data->f = ft_substr(line, 2, ft_strllen(line));
}

void	init_so(char *line, t_data *data)
{
	if (strncmp("SO", line, 2) == 0)
		data->so = ft_substr(line, 3, ft_strllen(line));
	if (strncmp("C", line, 1) == 0)
		data->c = ft_substr(line, 2, ft_strllen(line));
}

void	init_we(char *line, t_data *data)
{
	if (strncmp("WE", line, 2) == 0)
		data->we = ft_substr(line, 3, ft_strllen(line));
}

void	init_ea(char *line, t_data *data)
{
	if (strncmp("EA", line, 2) == 0)
		data->ea = ft_substr(line, 3, ft_strllen(line));
}
