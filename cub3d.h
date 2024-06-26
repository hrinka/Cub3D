/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirosuzu <hirosuzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:12:19 by hrinka            #+#    #+#             */
/*   Updated: 2024/06/17 23:58:23 by hirosuzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./MLX/MLX42.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# define WIDTH_WIN 1600
# define HEIGHT_WIN 900
# define SPEED_ROTATE 2
# define MOVE_STEP 0.1
// # define MOVE_STEP 3
# define VIEW_ANGLE 60

typedef struct s_paths
{
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
}					t_paths;

typedef struct s_textures
{
	mlx_image_t		*no_texture;
	mlx_image_t		*so_texture;
	mlx_image_t		*we_texture;
	mlx_image_t		*ea_texture;
	long			sky_hex;
	long			floor_hex;
}					t_textures;

typedef struct s_player
{
	int				i;
	int				j;
	char			direction;
	float			angle;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}					t_player;

typedef struct s_map
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*img_map;
	int				width_map;
	int				height_map;
	int				size_map;
	int				size_shape;
	char			**map;
	char			**tmp;
	// float			px;
	// float			py;
	double			old_x;
	// int				**world_map;
}					t_map;

typedef struct s_ray
{
	float		number_rays;
	double		ray_pos;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
}				t_ray;

typedef struct s_draw
{
	int			line_height;
	int			draw_start;	
	int			draw_end;
	double		wall_x;
	mlx_image_t	*texture_img;
	int			tex_x;
	int			tex_y;
}				t_draw;

// typedef struct s_render
// {
// 	float			number_rays;
// 	float			distance_horz;
// 	float			distance_vert;
// 	float			dist;
// 	float			hores_inters_x;
// 	float			hores_inters_y;
// 	float			vertcl_inters_x;
// 	float			vertcl_inters_y;
// 	float			next_hor_inters_x;
// 	float			next_hor_inters_y;
// 	float			next_ver_inters_x;
// 	float			next_ver_inters_y;
// 	float			step_hor_x;
// 	float			step_hor_y;
// 	float			step_ver_x;
// 	float			step_ver_y;
// 	float			steps;
// 	float			increamentx;
// 	float			increamenty;
// 	int				texture_offset_x;
// 	float			texture_offset_y;
// 	int				wall_start;
// 	float			present_texture;
// }					t_render;

typedef struct s_cub3d
{
	t_player		player;
	// t_render		render;
	t_ray			ray;
	t_map			map;
	t_textures		textures;
	t_paths			paths;
	char			**file_content;
	mlx_t			*mlx;
}					t_cub3d;

float				to_rad(float degree);
void				draw_line_dda(t_cub3d *data, float x2, float y2,
						uint32_t color);
float				distance_between_points(float x1, float y1, float x2,
						float y2);
// void				draw_map(t_cub3d *data, int mode);
void				draw_view_angle(t_cub3d *data);
// void				check_ray_draw(t_cub3d *data, float ray_angle, int id_ray);
void				ray_casting(t_cub3d *data, float ray_angle, int id_ray,
						mlx_image_t *img);
void				move_mouse(double xp, double yp, void *param);
void				draw_ceil_floor(t_cub3d *data);
void				controle_angle(t_cub3d *data);
void				controle_player(t_cub3d *data);
void				check_wall_2(t_cub3d *data, float *new_x, float *new_y);
int					check_wall(t_cub3d *data, float x, float y);
void				check_ray_draw(t_cub3d *data, float ray_angle, int id_ray);
void				check_ray_draw_down(t_cub3d *data, float ray_angle);
void				check_ray_draw_up(t_cub3d *data, float ray_angle);
void				check_ray_draw_right(t_cub3d *data, float ray_angle);
void				check_ray_draw_left(t_cub3d *data, float ray_angle);
void				call_raycasting(t_cub3d *data, float ray_angle, int id_ray);
void				draw_player(t_cub3d *data);

# define SUCCESS 1
# define FAILURE -1

int					ft_isdigit(int c);
size_t				ft_strlen(const char *s);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
void				*ft_realloc(void *ptr, size_t original_size, \
								size_t new_size);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*get_next_line(int fd);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strdup(const char *s1);
char				*remove_newline(char *str);
void				free_2dchar_array(char **arr);
void				free_cub_data(t_cub3d *data);
void				close_callback(void *param);

void				init_textures(mlx_t *mlx, t_cub3d *data);
int					check_extension(char *file, char *extension);
void				get_file_content(char *path, t_cub3d *data);
int					store_textures_path(t_cub3d *data, int length);
int					is_map_line(char *line);
int					empty_line(char *line);
int					check_if_map_line(char *line);
void				parse_file_content(t_cub3d *data);
int					store_map(t_cub3d *data, int index);

void				valid_texture_line(char *str, const char *needle);
int					check_which_texture(t_cub3d *data, int i,
						const char *direction);
int					check_path_rgb(t_cub3d *data);
void				check_map(t_map *data);
void				init_game(char *path_file, t_cub3d *data);

char				*skip_to_rgb_values(char *line);
long				rgb_to_hex(char *line);
uint32_t			get_texel(mlx_image_t *img, int x, int y);

void				check_comma(char *line);
int					beflastline(char **map, int y);
void				duplicate_player(t_cub3d *data);
void				get_player_pos(t_cub3d *data);
void				check_dimensions(t_map *data);
void				check_valid_path(t_cub3d *data, int y, int x);

void				raycasting(t_cub3d *data);
void				single_ray(t_cub3d *data, int id_ray);
void				init_ray(t_cub3d *data, t_ray *ray, int x);
void				init_player(t_player *player, t_cub3d *data);
void				print_ray(t_ray ray, t_player *player, int x);	
void				print_player(t_player *player);
void				render_wall(t_cub3d *data, t_ray *ray, int x);
void				ray_dist(t_player *player, t_ray *ray);
void				dda(t_cub3d *ray, char **map);
void				ray_vec(t_player *player, t_ray *ray);
// void				init_world_map(t_cub3d *data);
// void				print_world_map(t_cub3d *data, int **world_map);
void				print_map(char **map);
uint32_t			get_texel_image(mlx_image_t *image,
						uint32_t tex_x, uint32_t tex_y);

#endif