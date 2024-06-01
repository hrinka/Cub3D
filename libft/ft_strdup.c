/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:28:03 by hrinka            #+#    #+#             */
/*   Updated: 2022/11/15 12:01:43 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*cpy;

	i = 0;
	len = ft_strlen(s1);
	cpy = (char *) malloc (sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (NULL);
	while (i < len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

// int 	main(void)
// {
// 	char *s1;
// 	s1 = "Higher than the highest skyscraper.";

// 	printf ("%s\n", strdup(s1));
// 	printf ("%s\n", ft_strdup(s1));
// }
