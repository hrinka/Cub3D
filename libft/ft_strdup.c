/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:03:44 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/01/23 09:15:02 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = (char *)ft_xmalloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
}

/*
int main(){
	char a[] = "tkodai";
	char *test;

	test = ft_strdup(a);
}
*/
