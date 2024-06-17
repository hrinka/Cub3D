/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 06:24:53 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/06/17 23:56:13 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_realloc(void *ptr, size_t original_size, size_t new_size)
{
	void	*new;

	if (new_size == 0)
		return (NULL);
	new = ft_calloc(new_size, 1);
	if (!new)
		return (NULL);
	if (ptr)
	{
		if (original_size < new_size)
			ft_memmove(new, ptr, original_size);
		else
			ft_memmove(new, ptr, new_size);
	}
	free(ptr);
	return (new);
}
