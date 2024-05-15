CC				= cc
CFLAGS			= -Wall -Wextra -Werror

# MONDATORY
NAME			= so_long

INCLUDE_DIR		= ./includes
HEADERS			= cub3d.h

MLX_DIR			= ./minilibx-linux

SRC_DIR			= ./srcs
SRCS			= main.c \
				  read_and_create_map.c \
				  valid_map.c \
				  create_game_screen.c \
				  sl_utils.c \
				  mlx_utils.c \
				  mlx_keyhooks.c \
				  get_map_img.c \
