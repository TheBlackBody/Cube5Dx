/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:18:20 by sfernand          #+#    #+#             */
/*   Updated: 2023/10/10 20:55:12 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include "./mlx/mlx.h"
# include <fcntl.h>
# include "./libft/libft.h"
# include "./ft_printf/printf.h"
# include "./get_next_line/get_next_line.h"


typedef struct s_map_data
{
    char    *NO;
    char    *SO;
    char    *WE;
    char    *EA;
    char    *F;
    char    *C;
    char    **map;
}              t_data;

void    ft_close(void);
void    parse_path(char *path);
void    init_data(char *path);

#endif
