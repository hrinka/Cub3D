/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:12:24 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/06/05 17:20:59 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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
