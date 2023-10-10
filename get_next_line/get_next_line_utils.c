/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:21:51 by sfernand          #+#    #+#             */
/*   Updated: 2023/04/24 17:29:49 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

size_t	ft_strlen(const char *a)
{
	size_t	i;

	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		dest[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

void	ft_bzero(void *p, size_t n)
{
	size_t	i;
	char	*a;

	i = 0;
	a = (char *)p;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char		*dest;
	size_t		n;

	n = ((count * size));
	if (count != 0 && size >= SIZE_MAX / count)
		return (0);
	dest = (char *)malloc(sizeof(char *) * n);
	if (!dest)
	{
		return (NULL);
	}
	ft_bzero(dest, n);
	return (dest);
}
