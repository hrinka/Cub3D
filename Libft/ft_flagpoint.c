/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagpoint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 07:38:55 by hirosuzu          #+#    #+#             */
/*   Updated: 2023/10/14 08:50:22 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"printf.h"

void	ft_flagpoint(unsigned long long p, int *len)
{
	pf_putstr_fd("0x", 1);
	*len += 2;
	ft_xbase(p, 16, 0, len);
}
