/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:04:59 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/01/10 00:31:08 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;

	str = (char *)calloc(sizeof(char), n + 1);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, n);
	return (str);
}

// int main(){
// 	char a[] = "tkodai";
// 	char *test;

// 	test = ft_strndup(a+1,2);
// 	ft_strlen(test);
// 	printf("%s",test);
// }
