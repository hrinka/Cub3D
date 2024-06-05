# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 21:04:11 by hirosuzu          #+#    #+#              #
#    Updated: 2024/06/05 17:51:56 by hrinka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c get_next_line.c \
get_next_line_utils.c ft_strchar_position.c ft_realloc.c ft_isspace.c \
ft_abs.c ft_countwords.c ft_fabs.c ft_ischar.c ft_isspace.c \
ft_strtol.c ft_strndup.c ft_uppercase.c ft_xmalloc.c ft_printf.c \
ft_flagchar.c ft_flagstr.c ft_flagint.c ft_flagpoint.c ft_flagu.c \
ft_xbase.c pf_putchar_fd.c pf_putstr_fd.c pf_strlen.c

SRCS_BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c \
ft_lstnew.c ft_lstsize.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

ifdef WITH_BONUS
OBJS += $(OBJS_BONUS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus:
	make WITH_BONUS=1

main:
	$(CC) -g -fsanitize=address *.c
	./a.out

f: fclean
