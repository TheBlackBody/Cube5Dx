/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:18:20 by sfernand          #+#    #+#             */
/*   Updated: 2023/10/16 20:11:28 by sfernand         ###   ########.fr       */
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
char    **init_data(char *path, t_data *data);
void    init_NO(char *line, t_data *data);
void    init_SO(char *line, t_data *data);
void    init_WE(char *line, t_data *data);
void    init_EA(char *line, t_data *data);
void    verif_map(t_data data);
int     lenx(char **map, int y);

#endif
