/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:09:22 by gpolve-g          #+#    #+#             */
/*   Updated: 2023/11/23 17:33:30 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

t_image	*ft_select_text(t_pose *var, t_data *data)
{
	if (var->w_side == 0)
	{
		if (var->map_x > (int)var->x)
			return (&data->south);
		else
			return (&data->north);
	}
	else
	{
		if (var->map_y > (int)var->y)
			return (&data->west);
		else
			return (&data->east);
	}
}
