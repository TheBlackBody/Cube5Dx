/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:09:22 by gpolve-g          #+#    #+#             */
/*   Updated: 2023/11/24 14:02:10 by gpolve-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

t_image	*ft_select_text(t_pose *var, t_data *data)
{
	if (var->w_side == 0)
	{
		if (var->map_x > (int)var->x)
			return (&data->west);
		else
			return (&data->east);
	}
	else
	{
		if (var->map_y > (int)var->y)
			return (&data->north);
		else
			return (&data->south);
	}
}
