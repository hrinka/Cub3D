/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:13:24 by hirosuzu          #+#    #+#             */
/*   Updated: 2023/12/24 15:05:23 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	detect_base(const char **str)
{
	int	base;

	base = 10;
	if (**str == '0')
	{
		(*str)++;
		if (**str == 'x' || **str == 'X')
		{
			base = 16;
			(*str)++;
		}
		else
			base = 8;
	}
	return (base);
}

static long	convert_integer(const char *str, char **endptr, int base, int sign)
{
	long	result;
	char	c;
	int		digit;

	result = 0;
	while (*str != '\0')
	{
		c = *str;
		if (c >= '0' && c <= '9')
			digit = c - '0';
		else if (c >= 'A' && c <= 'Z')
			digit = c - 'A' + 10;
		else if (c >= 'a' && c <= 'z')
			digit = c - 'a' + 10;
		else
			break ;
		if (digit >= base)
			break ;
		result = result * base + digit;
		str++;
	}
	if (endptr != NULL)
		*endptr = (char *)str;
	return (result * sign);
}

long	ft_strtol(const char *str, char **endptr, int base)
{
	int		sign;

	if (!str)
		return (0);
	while (ft_isspace(*str))
		str++;
	sign = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
		if (*str == '+' || *str == '-')
			return (0);
	}
	if (base == 0)
		base = detect_base(&str);
	return (convert_integer(str, endptr, base, sign));
}
