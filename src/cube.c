/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:17:40 by sfernand          #+#    #+#             */
/*   Updated: 2023/10/10 20:28:36 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void    ft_close(void)
{
    exit(0);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_printf("argv = %s\n", argv[1]);
        parse_path(argv[1]);
        init_data(argv[1]);
    }
    else if (argc > 2) 
        ft_printf("Error : to many argument\n");
    else if (argc < 2) 
        ft_printf("Error : to less argument\n");
    return(0);
}