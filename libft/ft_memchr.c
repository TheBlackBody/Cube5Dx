/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:55:06 by sfernand          #+#    #+#             */
/*   Updated: 2022/11/11 02:08:04 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*a;

	i = 0;
	a = (const char *)s;
	while (i < n)
	{
		if (a[i] == (const char)c)
		{
			return ((void *)&a[i]);
		}
		i++;
	}
	return (0);
}
