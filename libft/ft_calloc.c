/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:49:59 by sfernand          #+#    #+#             */
/*   Updated: 2022/11/18 15:19:19 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*dest;
	size_t		n;

	n = (count * size);
	if (count != 0 && size >= SIZE_MAX / count)
		return (0);
	dest = (void *)malloc(n);
	if (!dest)
	{
		return (NULL);
	}
	ft_bzero(dest, n);
	return (dest);
}
