/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:17:40 by sfernand          #+#    #+#             */
/*   Updated: 2023/10/16 19:52:16 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void    ft_close(void)
{
    exit(0);
}

int main(int argc, char **argv)
{
    t_data  data;
    int     i;

    i = -1;
    if (argc == 2)
    {
        parse_path(argv[1]);
        data.map = init_data(argv[1], &data);
        while (data.map[i++] != NULL)
            ft_printf("%s\n", data.map[i]);
        verif_map(data);
        ft_printf("%s\n", data.map[11]);
    }
    else if (argc > 2) 
        ft_printf("Error : to many argument\n");
    else if (argc < 2) 
        ft_printf("Error : to less argument\n");
    return(0);
}
