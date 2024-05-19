/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:25:31 by hirosuzu          #+#    #+#             */
/*   Updated: 2023/12/15 09:55:28 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strchar_position(const char *str, int c)
{
	size_t	num;

	num = 1;
	if (c < 0 || c > 255)
	{
		while (c < 0)
			c += 256;
		while (c > 255)
			c -= 256;
	}
	while (*str)
	{
		if (*str == c)
			return (num);
		str++;
		num++;
	}
	if (*str == c)
		return (num);
	return (0);
}

// int main()
// {
// 	char a[] = "tkodai";
// 	size_t test;

// 	test = ft_strchar_position(a, 't');
// 	printf("%zu",test);
// }
