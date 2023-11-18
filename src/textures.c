/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolve-g <gpolve-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:09:22 by gpolve-g          #+#    #+#             */
/*   Updated: 2023/11/18 02:20:56 by gpolve-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

t_image	*ft_select_text(t_pose *var, t_data *data)
{
	if (var->w_side == 1)
	{
		if (var->map_y < (int)var->y)
			return (&data->south);
		else
			return (&data->north);
	}
	else
	{
		if (var->map_x > (int)var->x)
			return (&data->west);
		else
			return (&data->east);
	}
}
