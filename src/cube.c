/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:17:40 by sfernand          #+#    #+#             */
/*   Updated: 2023/10/10 23:38:16 by sfernand         ###   ########.fr       */
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

    ft_printf("\n\n ceci est un int: %i\n ceci est une chaine de char: %s  \n\n", 1, argv[1]);
    if (argc == 2)
    {
        ft_printf("argv = %s\n", argv[1]);
        parse_path(argv[1]);
        data.map = init_data(argv[1], &data);
        ft_printf("c\n");
    }
    else if (argc > 2) 
        ft_printf("Error : to many argument\n");
    else if (argc < 2) 
        ft_printf("Error : to less argument\n");
    return(0);
}
