/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolve-g <gpolve-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 02:45:36 by gpolve-g          #+#    #+#             */
/*   Updated: 2023/11/21 12:34:30 by gpolve-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static unsigned int	get_pixel_color(t_image *text, int x, int y)
{
	unsigned int	color;
	char			*pixel;

	x %= text->size.s_x;
	y %= text->size.s_y;
	pixel = text->pixels + (y * text->line_size
			+ x * (text->bits_per_pixel / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

static unsigned int	text_color(t_image *w_text, t_pose *var, int tex_x)
{
	int	tex_y;

	tex_y = (int)var->tex_pos & (w_text->size.s_y - 1);
	var->tex_pos += var->step;
	return (get_pixel_color(w_text, tex_x, tex_y));
}

static int	set_var_text(t_image *w_text, t_pose *var, t_mlx *mlx)
{
	double	wall_x;
	int		tex_x;

	if (var->w_side == 0)
		wall_x = var->y + var->len_ray * var->ray_dir_y;
	else
		wall_x = var->x + var->len_ray * var->ray_dir_x;
	wall_x -= (double)((int)wall_x);
	tex_x = (int)(wall_x * (double)w_text->size.s_x);
	if (var->w_side == 0 && var->ray_dir_x > 0)
		tex_x = w_text->size.s_x - tex_x - 1;
	if (var->w_side == 1 && var->ray_dir_y < 0)
		tex_x = w_text->size.s_x - tex_x - 1;
	var->step = 1.0 * w_text->size.s_y / var->line_height;
	var->tex_pos = (var->draw_start - mlx->size.s_y / 2
			+ var->line_height / 2) * var->step;
	return (tex_x);
}

static	void	ft_put_line(t_mlx *mlx, t_pose *var, int x, t_data *data)
{
	int		y;
	t_image	*w_text;
	int		tex_x;

	w_text = ft_select_text(var, data);
	tex_x = set_var_text(w_text, var, mlx);
	y = -1;
	while (++y < mlx->size.s_y)
	{
		if (y >= var->draw_start && y <= var->draw_end)
			ft_pixel_put(mlx, mlx->size.s_x - x - 1, y,
				text_color(w_text, var, tex_x));
		else if (y < var->draw_end)
			ft_pixel_put(mlx, mlx->size.s_x - x - 1, y,
				mcolor(0, ft_atoi(var->c[0]),
					ft_atoi(var->c[1]), ft_atoi(var->c[2])));
		else
			ft_pixel_put(mlx, mlx->size.s_x - x - 1, y,
				mcolor(0, ft_atoi(var->f[0]),
					ft_atoi(var->f[1]), ft_atoi(var->f[2])));
	}
}

void	ft_line_height(t_mlx *mlx, t_pose *var, int x, t_data *data)
{
	var->line_height = (int)(mlx->size.s_y / var->len_ray);
	var->draw_start = -(var->line_height) / 2 + mlx->size.s_y / 2;
	if (var->draw_start < 0)
		var->draw_start = 0;
	var->draw_end = var->line_height / 2 + mlx->size.s_y / 2;
	if (var->draw_end >= mlx->size.s_y)
		var->draw_end = mlx->size.s_y - 1;
	ft_put_line(mlx, var, x, data);
}
