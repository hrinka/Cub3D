/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:05:10 by hrinka            #+#    #+#             */
/*   Updated: 2024/06/01 19:43:35 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ret_doublep(char const *s, char c)
{
	size_t	i;
	int		splen;

	if (!s)
		return (NULL);
	i = 0;
	splen = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			splen++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return ((char **)ft_calloc(splen + 1, sizeof(char *)));
}

void	*ft_memcpy(void	*dst, const void *src, size_t	n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (dst == src)
		return (dst);
	s = (const unsigned char *)src;
	d = (unsigned char *)dst;
	while (n--)
		*d++ = *s++;
	return (dst);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = (char *)ft_calloc(n + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s, n);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	sp_ind;
	char	**sp;

	i = 0;
	sp_ind = 0;
	sp = ret_doublep(s, c);
	if (sp == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			sp[sp_ind] = ft_strndup(s + j, i - j);
			sp_ind++;
		}
	}
	return (sp);
}
