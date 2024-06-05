/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:31:49 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/06/05 17:20:53 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_flagint(int n, int *len)
{
	if (n == INT_MIN)
	{
		pf_putstr_fd("-2147483648", 1);
		*len += 11;
		return ;
	}
	else if (n < 0)
	{
		pf_putchar_fd('-', 1);
		ft_flagint(n * (-1), len);
		*len += 1;
	}
	else
	{
		if (n >= 10)
			ft_flagint(n / 10, len);
		pf_putchar_fd((n % 10 + '0'), 1);
		*len += 1;
	}
}
