/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:19:08 by hirosuzu          #+#    #+#             */
/*   Updated: 2023/06/04 16:52:47 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;

	if (!s)
		return (NULL);
	size = len;
	if (ft_strlen(s) < start || len == 0)
		return ((char *)ft_calloc(0, sizeof(char)));
	else if (ft_strlen(s) < len)
		size = ft_strlen(s);
	str = (char *)ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memmove(str, s + start, size);
	return (str);
}
