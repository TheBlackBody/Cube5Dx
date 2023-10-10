/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:13:17 by sfernand          #+#    #+#             */
/*   Updated: 2023/04/27 12:09:57 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	s;
	size_t	d;

	j = 0;
	if (!dst && size == 0)
		return (0);
	d = ft_strllen(dst);
	s = ft_strllen(src);
	i = d;
	if (size < d)
		return (s + size);
	else
	{
		while (src[j] && (d + j) < size)
			dst[i++] = src[j++];
		if ((d + j) == size && d < size)
			dst[--i] = '\0';
		else
			dst[i] = '\0';
		return (s + d);
	}
}
