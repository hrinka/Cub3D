/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:12:24 by hirosuzu          #+#    #+#             */
/*   Updated: 2023/10/14 08:50:44 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"printf.h"

void	ft_flagstr(char *s, int *len)
{
	if (s == NULL)
	{
		pf_putstr_fd("(null)", 1);
		*len += 6;
		return ;
	}
	pf_putstr_fd(s, 1);
	*len += pf_strlen(s);
}
