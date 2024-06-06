/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:36:42 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/06/05 17:03:57 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*chr;
	size_t			i;

	chr = (unsigned char *)buf;
	i = 0;
	while (i < n)
	{
		chr[i] = ch;
		i++;
	}
	return (buf);
}
