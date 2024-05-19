/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:14:14 by hirosuzu          #+#    #+#             */
/*   Updated: 2023/06/05 20:46:18 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*s1_reverse;
	char		*str;
	size_t		len;

	if (s1 == NULL)
		return (NULL);
	s1_reverse = s1 + ft_strlen(s1) - 1;
	while (*s1 && ft_strchr(set,*s1))
		s1++;
	while (*s1_reverse && ft_strchr(set,*s1_reverse))
	{
		if (s1_reverse - s1 < 0)
			return ((char *) ft_calloc (1, 1));
		s1_reverse--;
	}
	len = s1_reverse - s1;
	str = (char *)ft_calloc(len + 2, sizeof(char));
	if (!str)
		return (NULL);
	return (ft_memmove(str, s1, len + 1));
}
