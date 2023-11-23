/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:21:36 by sfernand          #+#    #+#             */
/*   Updated: 2023/04/27 12:11:24 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		n;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (ft_strdup(""));
	len1 = ft_strllen(s1);
	len2 = ft_strllen(s2);
	i = 0;
	dest = malloc(len1 + len2 + 1);
	if (!dest)
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	n = 0;
	while (s2[n])
		dest[i++] = s2[n++];
	dest[i] = '\0';
	return (dest);
}
