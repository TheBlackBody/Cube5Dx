/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:01:48 by sfernand          #+#    #+#             */
/*   Updated: 2022/11/14 17:32:49 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	char	*a;
	char	*c;

	i = 0;
	a = (char *)dest;
	c = (char *)src;
	if (a == NULL && c == NULL && len > 0)
		return (dest);
	if (a > c)
	{
		while (len > 0)
		{
			a[len - 1] = c[len - 1];
			len --;
		}
	}
	else
	{
		i = 0;
		while (i++ < len)
			a[i - 1] = c[i - 1];
	}
	return (dest);
}
