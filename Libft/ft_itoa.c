/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:19:45 by hirosuzu          #+#    #+#             */
/*   Updated: 2023/12/07 09:39:28 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	itoa_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

static int	ft_numlen(int n, char *str, int len)
{
	int	i;
	int	num;

	i = 0;
	num = n;
	while (num != 0)
	{
		if (len && str)
			str[len - i - 1] = itoa_abs(num % 10) + '0';
		num /= 10;
		i++;
	}
	if (n <= 0)
	{
		i += 1;
		if (len && str)
			str[0] = '-';
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		numlen;

	if (n == 0)
		return (ft_strdup("0"));
	numlen = ft_numlen(n, NULL, 0);
	str = (char *)ft_calloc(numlen + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_numlen(n, str, numlen);
	return (str);
}

// int main()
//  {
//     // printf("itoa = [%s]\n",ft_itoa(1));
// 	// printf("itoa = [%s]\n",ft_itoa(+1));
//     // printf("itoa = [%s]\n",ft_itoa(7));
// 	printf("itoa = [%s]\n",ft_itoa(-1234));
// 	printf("itoa = [%s]\n",ft_itoa(-5859));
//  }