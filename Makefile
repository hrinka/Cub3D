# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 09:52:44 by hirosuzu          #+#    #+#              #
#    Updated: 2024/05/15 09:01:32 by hirosuzu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d
SRCS	=	main.c raycasting.c player.c

OBJS = $(SRCS:.c=.o)
LIBFTDIR = Libft/
LIBFTNAME = libft.a
# PRINTFDIR = printf/
# PRINTFNAME = libftprintf.a
LIBFT = $(LIBFTDIR)$(LIBFTNAME)
# PRINTF = $(PRINTFDIR)$(PRINTFNAME)
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
# CFLAGS = -g -fsanitize=address
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTNAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTNAME) -Imlx -lmlx -framework OpenGL -framework AppKit

$(LIBFTNAME): 
	make -C $(LIBFTDIR) 
	cp $(LIBFT) ./

# $(PRINTFNAME): 
# 	make -C $(PRINTFDIR)
# 	cp $(PRINTF) ./

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	make clean -C $(LIBFTDIR)
	# make clean -C $(PRINTFDIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(LIBFTNAME)
	# $(RM) $(PRINTF)
	# $(RM) $(PRINTFNAME)
	$(RM) $(NAME)

re: fclean all

# main:
# 	cc -g -fsanitize=address -Imlx -lmlx -framework OpenGL -framework AppKit Libft/*.c printf/*.c *.c

.PHONY: all clean fclean re


