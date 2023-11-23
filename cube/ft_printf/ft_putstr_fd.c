/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:26:17 by sfernand          #+#    #+#             */
/*   Updated: 2023/10/09 20:35:36 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

int	ft_putstr_fd(const char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	else
		return (ft_putstr_fd("(null)", 1));
	return (i);
}
