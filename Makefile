# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 08:44:19 by hrinka            #+#    #+#              #
#    Updated: 2024/06/06 09:20:46 by hirosuzu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

FRAMEWORKS = ./MLX/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit

# FLAGS = -Wall -Wextra -Werror
FLAGS = -g -fsanitize=address

PARSE_SRC =  parsing/check_utils.c parsing/texel.c parsing/free_resources.c parsing/rgb_conversion.c parsing/get_file_data.c parsing/init_data.c parsing/store_data.c parsing/check_map_utils.c parsing/check_map_utils2.c parsing/file_parser.c parsing/check_player.c parsing/store_data_utils.c

GNL_SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

LIBFT_SRC = libft/ft_isdigit.c libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strchr.c libft/ft_calloc.c libft/ft_bzero.c libft/ft_strnstr.c libft/ft_atoi.c libft/ft_strdup.c libft/ft_split.c libft/ft_memset.c libft/ft_isspace.c \
				libft/ft_memcpy.c libft/ft_substr.c libft/ft_xmalloc.c libft/ft_memmove.c libft/ft_printf.c libft/ft_flagchar.c libft/ft_flagpoint.c libft/ft_flagstr.c libft/ft_flagint.c libft/ft_flagu.c libft/ft_xbase.c libft/pf_putchar_fd.c libft/pf_putstr_fd.c libft/pf_strlen.c

ABD_SRC = move_mouse.c move_player.c raycasting_2.c raycasting.c tools.c draw_map.c draw_player.c cub3d.c my_raycasting.c

OBJ = $(PARSE_SRC:.c=.o) $(GNL_SRC:cpp=.o) $(LIBFT_SRC:.c=.o) $(ABD_SRC:.c=.o)


all: $(NAME)

bonus: all

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $^ $(FRAMEWORKS) -o $@


%.o: %.c
	$(CC) $(FLAGS)  -Imlx -c $< -o $@

clean :
	@find . -name "*.o" -type f -delete

fclean : clean
	@rm -rf $(NAME)

re : fclean all
