/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:00:42 by sfernand          #+#    #+#             */
/*   Updated: 2023/11/23 17:21:06 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

void	init_no(char *line, t_data *data)
{
	if (strncmp("NO", line, 2) == 0)
	{
		free(data->no);
		data->no = ft_substr(line, 3, ft_strllen(line));
	}
	if (strncmp("F", line, 1) == 0)
	{
		free(data->f);
		data->f = ft_substr(line, 2, ft_strllen(line));
	}
}

void	init_so(char *line, t_data *data)
{
	if (strncmp("SO", line, 2) == 0)
	{
		free(data->so);
		data->so = ft_substr(line, 3, ft_strllen(line));
	}
	if (strncmp("C", line, 1) == 0)
	{
		free(data->c);
		data->c = ft_substr(line, 2, ft_strllen(line));
	}
}

void	init_we(char *line, t_data *data)
{
	if (strncmp("WE", line, 2) == 0)
	{
		free(data->we);
		data->we = ft_substr(line, 3, ft_strllen(line));
	}
}

void	init_ea(char *line, t_data *data)
{
	if (strncmp("EA", line, 2) == 0)
	{
		free(data->ea);
		data->ea = ft_substr(line, 3, ft_strllen(line));
	}
}
