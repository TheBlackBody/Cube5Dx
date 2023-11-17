/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolve-g <gpolve-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:09:22 by gpolve-g          #+#    #+#             */
/*   Updated: 2023/11/17 23:47:51 by gpolve-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

t_image	*ft_select_text(t_pose *var, t_data *data)
{
	if (var->w_side == 1)
	{
		if (var->map_y < (int)var->y)
		{
//			var->side = 2;
			return (&data->south);
		}
		else
		{
//			var->side = 1;
			return (&data->north);
		}
	}
	else
	{
		if (var->map_x > (int)var->x)
		{
//			var->side = 3;
			return (&data->west);
		}
		else
		{
//			var->side = 4;
			return (&data->east);
		}
	}
}
