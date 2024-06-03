/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 23:17:43 by hrinka            #+#    #+#             */
/*   Updated: 2022/12/01 21:41:41 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// int main(void)
// {
// 	char *dst = NULL;
// 	const char *src = "hogehoge";
// 	char *ret;
// 	printf ("%s\n", ft_printf())

// }
