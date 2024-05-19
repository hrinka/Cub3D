/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:51:38 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/01/23 09:14:12 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	get_nl(const char *str)
{
	ssize_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] != '\0' && str[i] == '\n')
		return (i + 1);
	return (0);
}

char	*read_line(int fd, char *line)
{
	char		*buf;
	ssize_t		read_len;
	char		*str;

	str = gnl_strndup(line, gnl_strlen(line));
	if (!str && line)
		return (NULL);
	buf = (char *)ft_xmalloc((sizeof(char)) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (gnl_strndup(str, -1));
	while (1)
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len <= 0)
			break ;
		buf[read_len] = '\0';
		str = gnl_strjoin(str, buf, read_len);
		if (get_nl(buf) != 0 || !str)
			break ;
	}
	free(buf);
	if (read_len == -1 || !str)
		return (gnl_strndup(str, -1));
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		*ret;
	ssize_t		size;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	size = 0;
	if (get_nl(line[fd]) == 0)
		ret = read_line(fd, line[fd]);
	else
		ret = gnl_strndup(line[fd], gnl_strlen(line[fd]));
	line[fd] = NULL;
	size = get_nl(ret);
	if (size == 0)
		size = gnl_strlen(ret);
	line[fd] = gnl_substr(ret, size);
	if (!line[fd])
		ret = NULL;
	ret = gnl_strndup(ret, size);
	if (ret == NULL || (line[fd] && !*line[fd]))
	{
		free(line[fd]);
		line[fd] = NULL;
	}
	return (ret);
}
