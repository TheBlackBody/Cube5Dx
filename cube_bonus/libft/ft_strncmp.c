/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:04:42 by sfernand          #+#    #+#             */
/*   Updated: 2022/11/12 13:02:45 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned const char	*a;
	unsigned const char	*b;

	i = 0;
	a = (unsigned const char *)s1;
	b = (unsigned const char *)s2;
	while (i < n)
	{
		if (b[i] != a[i])
			return (a[i] - b[i]);
		if (a[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
