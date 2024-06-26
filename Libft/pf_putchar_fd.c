/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:24:48 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/06/05 17:17:11 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	pf_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
