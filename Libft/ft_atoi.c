/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:22:14 by hirosuzu          #+#    #+#             */
/*   Updated: 2023/12/16 09:41:46 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static long	ft_overflow(const char *str, int sign)
{
	long long	result;
	int			digit;

	result = 0;
	while (*str >= '0' && *str <= '9' )
	{
		digit = *str - '0';
		if (sign == 1)
		{
			if (result * sign > LONG_MAX / 10
				|| (result == LONG_MAX / 10
					&& digit > LONG_MAX % 10))
				return (LONG_MAX);
		}
		else
		{
			if (result * sign < LONG_MIN / 10
				|| (result * sign == LONG_MIN / 10
					&& digit * sign < LONG_MIN % 10))
				return (LONG_MIN);
		}
		result = result * 10 + digit;
		str++;
	}
	return (result * sign);
}

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
		if (*str == '+' || *str == '-')
			return (0);
	}
	return ((int)ft_overflow(str, sign));
}
