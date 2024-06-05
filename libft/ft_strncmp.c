/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:18:02 by hirosuzu          #+#    #+#             */
/*   Updated: 2023/05/27 17:26:25 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s11;
	const unsigned char	*s22;

	s11 = (const unsigned char *)s1;
	s22 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s11[i] == s22[i])
	{
		if (s11[i] == '\0')
			return (0);
		i++;
		if (i == n)
			return (s11[i - 1] - s22[i - 1]);
	}
	return (s11[i] - s22[i]);
}
