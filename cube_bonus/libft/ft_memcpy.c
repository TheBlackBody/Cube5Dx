/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:39:18 by sfernand          #+#    #+#             */
/*   Updated: 2022/11/11 04:38:46 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	*ft_memcpy(void *r_dest, const void *r_src, size_t n)
{
	size_t		i;
	char		*a;
	const char	*b;

	i = 0;
	a = (char *)r_dest;
	b = (char *)r_src;
	if (a == NULL && b == NULL)
		return (0);
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (r_dest);
}
