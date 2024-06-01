/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:06:30 by hrinka            #+#    #+#             */
/*   Updated: 2023/06/26 21:42:13 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char	*str)
{
	long	num;
	int		i;
	int		neg;

	num = 0;
	i = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * neg);
}

// int	main(void)
// {
// 	char	str[]= "-153678";

// 	printf ("%d\n", ft_atoi(str));
// 	printf ("%d\n", atoi (str));
// }
// INT_MAX < num <= LONG_MAX -> (int) num
// return ((int)res);

// LONG_MAX < (int)LONG_MAX
// return ((int)res);

// INT_MAX "4byte" bit 01111111 11111111 11111111 11111111
// 					10000000 00000000 00000000 00000000

// 					if LONG_MAX < num * 10 + (str[i] - '0');
