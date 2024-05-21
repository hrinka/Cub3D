/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 03:37:48 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/01/23 09:20:00 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
// # include <stdio.h> //printf
// # include <ctype.h> //is~~
// # include <string.h> //str~~
// # include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(const char *print, ...);
void	ft_flagchar(int c, int *len);
void	ft_flagstr(char *s, int *len);
void	ft_flagint(int n, int *len);
void	ft_flagpoint(unsigned long long p, int *len);
void	ft_flagu(unsigned long long u, int *len);
void	ft_xbase(unsigned long long n, int base, int istoupper, int *len);
void	pf_putchar_fd(char c, int fd);
void	pf_putstr_fd(char *s, int fd);
size_t	pf_strlen(const char *str);

#endif
