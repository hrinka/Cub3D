/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:12:42 by hirosuzu          #+#    #+#             */
/*   Updated: 2023/07/09 22:47:47 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"printf.h"

int	ft_flagjudge(int c, va_list args)
{
	int	i;
	int	*len;

	i = 0;
	len = &i;
	if (c == 'c')
		ft_flagchar(va_arg(args, int), len);
	else if (c == 's')
		ft_flagstr(va_arg(args, char *), len);
	else if (c == 'p')
		ft_flagpoint((unsigned long long)va_arg(args, void *), len);
	else if (c == 'd' || c == 'i')
		ft_flagint(va_arg(args, int), len);
	else if (c == 'u')
		ft_flagu((unsigned long long)va_arg(args, unsigned long long), len);
	else if (c == 'x')
		ft_xbase(va_arg(args, unsigned int), 16, 0, len);
	else if (c == 'X')
		ft_xbase(va_arg(args, unsigned int), 16, 1, len);
	else if (c == '%')
		ft_flagstr("%", len);
	return (*len);
}

int	ft_printlen(const char *print, va_list args)
{
	int	num;

	num = 0;
	while (*print)
	{
		if (*print == '%')
		{
			print++;
			num += ft_flagjudge(*print, args);
		}
		else
		{
			write(1, &*print, 1);
			num++;
		}
		if (!(*print))
			return (num);
		print++;
	}
	return (num);
}

int	ft_printf(const char *print, ...)
{
	va_list	args;
	int		num;

	va_start(args, print);
	num = ft_printlen(print, args);
	va_end(args);
	return (num);
}
