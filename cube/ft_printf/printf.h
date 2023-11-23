/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:19:36 by sfernand          #+#    #+#             */
/*   Updated: 2022/12/06 16:34:04 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_size
{
	int	len;
	int	widht;
}				t_size;

int		ft_printf(const char *str, ...);
int		ft_putunbr_fd(unsigned int n, int fd);
int		ft_hexa(unsigned int num, const char str);
int		ft_void_hexa(unsigned long hexa);

#endif
