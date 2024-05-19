/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:53:17 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/01/23 09:14:20 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char *s1, char *buf, ssize_t read_len)
{
	char	*str;
	ssize_t	s1len;

	if (!buf)
		return (NULL);
	s1len = gnl_strlen(s1);
	str = (char *)ft_xmalloc((s1len + read_len + 1) * (sizeof(char)));
	if (str == NULL)
	{
		free (s1);
		return (NULL);
	}
	if (s1)
	{
		gnl_memmove(str, s1, s1len);
		free(s1);
	}
	gnl_memmove(str + s1len, buf, read_len);
	str[s1len + read_len] = '\0';
	return (str);
}

void	*gnl_strndup(char *s1, ssize_t len)
{
	char	*dup;

	if (!s1 || !*s1 || len == -1)
	{
		free(s1);
		return (NULL);
	}
	dup = (char *)ft_xmalloc((sizeof(char)) * (len + 1));
	if (dup == NULL)
	{
		free(s1);
		return (NULL);
	}
	gnl_memmove(dup, s1, len);
	dup[len] = '\0';
	if (len > 0)
		free(s1);
	return (dup);
}

char	*gnl_substr(char *s, ssize_t start)
{
	char	*str;
	ssize_t	size;

	if (!s || !*s)
	{
		free (s);
		return (NULL);
	}
	size = gnl_strlen(s + start);
	str = (char *)ft_xmalloc((sizeof(char)) * (size + 1));
	if (!str)
	{
		free (s);
		return (NULL);
	}
	gnl_memmove(str, s + start, size);
	str[size] = '\0';
	return (str);
}

ssize_t	gnl_strlen(const char *str)
{
	ssize_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*gnl_memmove(void *dst, const void *src, ssize_t n)
{
	ssize_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst || !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (s < d && n > 0)
	{
		d = d + n - 1;
		s = s + n - 1;
		while (n--)
			*d-- = *s--;
	}
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
