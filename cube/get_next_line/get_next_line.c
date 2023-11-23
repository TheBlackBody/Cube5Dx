/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <sfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:45:05 by sfernand          #+#    #+#             */
/*   Updated: 2023/04/18 17:42:09 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join(char *res, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(res, buffer);
	free (res);
	return (temp);
}

char	*put_next_line(char *buff)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	next = ft_calloc((ft_strlen(buff) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buff[i])
		next[j++] = buff[i++];
	free (buff);
	buff = NULL;
	return (next);
}

char	*put_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] && buff[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *res_buff)
{
	char	*buffer;
	int		n_read;

	if (!res_buff)
		res_buff = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	n_read = 1;
	while (n_read > 0)
	{
		n_read = read(fd, buffer, BUFFER_SIZE);
		if (n_read <= -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[n_read] = '\0';
		res_buff = join(res_buff, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free (buffer);
	buffer = NULL;
	return (res_buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = put_line(buffer);
	buffer = put_next_line(buffer);
	return (line);
}
