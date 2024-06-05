/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 07:37:38 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/06/05 21:53:45 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// # include <stdio.h>
// # include <ctype.h>
// # include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "printf.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *buf, int ch, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	*ft_memmove(void *dst, const void *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strdup(const char *s1);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
int		ft_abs(int i);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	*ft_realloc(void *ptr, size_t original_size, size_t new_size);
size_t	ft_countwords(char const *s, char c);
char	*ft_strndup(const char *s1, size_t n);
int		ft_ischar(const char *str, int c);
int		ft_isspace(int c);
long	ft_strtol(const char *str, char **endptr, int base);
size_t	ft_strchar_position(const char *str, int c);
double	ft_fabs(double i);
int		ft_uppercase(int a, int b);
void	*ft_xmalloc(size_t size);
int		ft_printf(const char *print, ...);
int		ft_flagjudge(int c, va_list args);
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
