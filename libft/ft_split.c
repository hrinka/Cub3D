/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 06:16:23 by hirosuzu          #+#    #+#             */
/*   Updated: 2023/12/15 07:52:04 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_split_countwords(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && c == *s)
			s++;
		if (*s != '\0')
			count++;
		while (*s && c != *s)
			s++;
	}
	return (count);
}

static char	**ft_split_free(char **str, size_t i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

static char	**fill_with_split(char **str, char const *s, char c, size_t count)
{
	size_t	i;
	char	**origin;

	origin = str;
	while (*s)
	{
		i = 0;
		while (*(s + i) != c && *(s + i) != '\0')
			i++;
		if (i != 0)
		{
			*str = ft_substr(s, 0, i);
			if (!*str)
				return (ft_split_free(str, str - origin));
			str++;
		}
		s += i;
		if (!*s)
			return (str - count);
		s++;
	}
	return (str - count);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	count;

	if (s == NULL)
		return (NULL);
	count = ft_split_countwords(s, c);
	str = (char **)ft_calloc(count + 1, sizeof(char *));
	if (str == NULL)
		return (NULL);
	str = fill_with_split(str, s, c, count);
	return (str);
}
