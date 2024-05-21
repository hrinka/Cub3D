/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:34:37 by hirosuzu          #+#    #+#             */
/*   Updated: 2023/06/04 21:57:22 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	if (c < 0 || c > 255)
	{
		while (c < 0)
			c += 256;
		while (c > 255)
			c -= 256;
	}
	while (n > i && str[i] != c)
		i++;
	if (n > i && str[i] == c)
		return ((void *)&str[i]);
	return (NULL);
}

// int main (){
// 	ft_memchr(":(){ :|: & };:", '\xde', 15);
// 	// char *s = calloc(30, sizeof(char));
// 	// memcpy(s, "libft-test-tokyo", 17);
// 	// memcpy(s + 20, "acdfg", 5);
// 	// printf("mem = [%p],%s\n",ft_memchr(s, 'a', 30),ft_memchr(s, 'a', 30)); 
// 	// printf("ft_mem = [%p],%s\n",memchr(s, 'a', 30),memchr(s, 'a', 30));
// }