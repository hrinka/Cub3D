/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_schr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:23:13 by hrinka            #+#    #+#             */
/*   Updated: 2022/11/27 21:51:40 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)c == *s)
			return ((char *)s);
		s++;
	}
	if ((char)c == 0)
		return ((char *)s);
	return (NULL);
}

//int	main(void)
//{
//	char	*s;
//	char	c;
//
//	s = "ahijidfjijdiji8hhqhj";
//	c = 'q';
//	printf("%p\n", strchr(s, c));
//	printf("%p\n", ft_strchr(s, c));
//}
