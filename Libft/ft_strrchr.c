/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:14:15 by hirosuzu          #+#    #+#             */
/*   Updated: 2023/06/10 03:03:45 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*chr;

	chr = "\0";
	if (c < 0 || c > 255)
	{
		while (c < 0)
			c += 256;
		while (c > 255)
			c -= 256;
	}
	while (*s)
	{
		if (*s == c)
			chr = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	else if (*chr == '\0')
		return (NULL);
	else if (*chr == c)
		return ((char *)chr);
	return (NULL);
}

// //strrchr
// int main(){
// 	char *s = "libft-test-tokyo";
// 	printf("a\n");
// 	printf("%s",ft_strrchr(s, 'z'));
// 	printf("%s",strrchr(s, 'z'));
// }