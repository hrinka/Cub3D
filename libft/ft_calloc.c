/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:37:29 by hrinka            #+#    #+#             */
/*   Updated: 2023/11/05 15:36:33 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (SIZE_MAX / count < size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr, size * count);
	return (ptr);
}

// int	main (void)
// {
// 	long	*pMMem;	//for malloc
// 	long	*pCMem;	//for calloc
// 	long	*ftMem;	//for ft_calloc

// 	pMMem = (long *)malloc (sizeof(long) * '\0');
// 	pCMem = (long *)calloc (SIZE_MAX, SIZE_MAX);
// 	ftMem = (long *)ft_calloc (SIZE_MAX, SIZE_MAX);

// 	//確保領域の初期値表示
// 	printf("malloc [0]:%ld, [1]:%ld, [2]:%ld\n", pMMem[0], pMMem[1], pMMem[2]);
// 	printf("calloc [0]:%ld, [1]:%ld, [2]:%ld\n", pCMem[0], pCMem[1], pCMem[2]);
// 	printf("ft_calloc %ld, %ld, %ld\n", ftMem[0], ftMem[1], ftMem[2]);

// 	free(pMMem);
// 	free(pCMem);
// 	free(ftMem);

// 	return (0);
// }
