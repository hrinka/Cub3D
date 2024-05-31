# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 08:44:19 by hrinka            #+#    #+#              #
#    Updated: 2024/05/31 23:19:50 by hrinka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

FRAMEWORKS = ~/42Tokyo/cub3d-test/MLX/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit

FLAGS = -Wall -Wextra -Werror

PARSE_SRC =  parsing/check_utils.c parsing/texel.c parsing/free_resources.c parsing/rgb_conversion.c parsing/get_file_data.c parsing/init_data.c parsing/store_data.c parsing/check_map_utils.c parsing/check_map_utils2.c parsing/file_parser.c parsing/check_player.c parsing/store_data_utils.c

GNL_SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

LIBFT_SRC = libft/ft_isdigit.c libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strchr.c libft/ft_calloc.c libft/ft_bzero.c libft/ft_strnstr.c libft/ft_atoi.c libft/ft_strdup.c libft/ft_split.c

ABD_SRC = mouve_mouse.c move_player.c raycasting_2.c raycasting.c tools.c draw_map.c draw_player.c cub3d.c

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
