/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:56:24 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/01/23 09:18:37 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

char		*get_next_line(int fd);
char		*gnl_strjoin(char *s1, char *s2, ssize_t read_len);
ssize_t		gnl_strlen(const char *str);
ssize_t		get_nl(const char *str);
void		*gnl_memmove(void *dst, const void *src, ssize_t n);
void		*gnl_strndup(char *s1, ssize_t len);
char		*gnl_substr(char *s, ssize_t start);
char		*read_line(int fd, char *line_len);

#endif
