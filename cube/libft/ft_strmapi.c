/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:24:21 by sfernand          #+#    #+#             */
/*   Updated: 2023/04/27 12:13:00 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dst;

	i = 0;
	if (!s || !f)
		return (NULL);
	dst = malloc(ft_strllen(s) + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s, ft_strllen(s) + 1);
	while (dst[i])
	{
		dst[i] = (*f)(i, dst[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
