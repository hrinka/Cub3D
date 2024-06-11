/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:04:16 by hirosuzu          #+#    #+#             */
/*   Updated: 2024/06/11 16:55:51 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	render_wall(t_cub3d *data, t_ray *ray, int x)
// {
// 	int line_height = (int)(HEIGHT_WIN / ray->wall_dist);
// 	int draw_start = -line_height / 2 + HEIGHT_WIN / 2;
// 	if (draw_start < 0)
// 		draw_start = 0;
// 	int draw_end = line_height / 2 + HEIGHT_WIN / 2;
// 	if (draw_end >= HEIGHT_WIN)
// 		draw_end = HEIGHT_WIN - 1;
// 	double wall_x = ray->side == 0 ? data->player.pos_y + ray->wall_dist * ray->ray_dir_y
//                                    : data->player.pos_x + ray->wall_dist * ray->ray_dir_x;
//     wall_x -= floor(wall_x);
// 	// int tex_num = ray->side;  // テクスチャ番号を取得
// 	mlx_image_t		**images[4];
// 	// int				i;

// 	images[0] = &data->textures.no_texture;
// 	images[1] = &data->textures.so_texture;
// 	images[2] = &data->textures.ea_texture;
// 	images[3] = &data->textures.we_texture;
//     mlx_texture_t *texture = data->textures.no_texture;  // テクスチャを取得
//     if (!texture)
// 	{
//         fprintf(stderr, "Failed to get texture\n");
//         return;
//     }
	
// 	int tex_x = (int)(wall_x * (double)(texture->width));
// 	if (ray->side == 0 && ray->ray_dir_x > 0) tex_x = texture->width - tex_x - 1;
//     if (ray->side == 1 && ray->ray_dir_y < 0) tex_x = texture->width - tex_x - 1;
// 	uint32_t color;
// 	color = 0x00FF0000;
// 	for (int y = draw_start; y < draw_end; y++)
// 	{
//         int d = y * 256 - HEIGHT_WIN * 128 + line_height * 128;
//         int tex_y = ((d * texture->height) / line_height) / 256;
//         uint32_t color = get_texel(*images[ray->side], tex_x, tex_y);
//         mlx_put_pixel(data->map.img, x, y, color);
//     }
// 	// draw_line(data, x, draw_start, draw_end, color);
// }

// void render_wall(t_cub3d *data, t_ray *ray, int x)
// {
//     int line_height = (int)(HEIGHT_WIN / ray->wall_dist);
//     int draw_start = -line_height / 2 + HEIGHT_WIN / 2;
//     if (draw_start < 0) draw_start = 0;
//     int draw_end = line_height / 2 + HEIGHT_WIN / 2;
//     if (draw_end >= HEIGHT_WIN) draw_end = HEIGHT_WIN - 1;

//     double wall_x = ray->side == 0 ? data->player.pos_y + ray->wall_dist * ray->ray_dir_y
//                                    : data->player.pos_x + ray->wall_dist * ray->ray_dir_x;
//     wall_x -= floor(wall_x);

//     // テクスチャ番号を取得し、適切なテクスチャを選択
//     int tex_num = ray->side;  
//     mlx_image_t *texture_img = data->textures.no_texture;
//     if (tex_num == 1) texture_img = data->textures.so_texture;
//     else if (tex_num == 2) texture_img = data->textures.ea_texture;
//     else if (tex_num == 3) texture_img = data->textures.we_texture;

//     if (!texture_img) {
//         fprintf(stderr, "Failed to get texture image\n");
//         return;
//     }

//     int tex_x = (int)(wall_x * (double)(texture_img->width));
//     if (ray->side == 0 && ray->ray_dir_x > 0) tex_x = texture_img->width - tex_x - 1;
//     if (ray->side == 1 && ray->ray_dir_y < 0) tex_x = texture_img->width - tex_x - 1;

//     for (int y = draw_start; y < draw_end; y++) {
//         int d = y * 256 - HEIGHT_WIN * 128 + line_height * 128;
//         int tex_y = ((d * texture_img->height) / line_height) / 256;
//         uint32_t color = get_texel_from_image(texture_img, tex_x, tex_y);
//         mlx_put_pixel(data->map.img, x, y, color);
//     }
// }

// uint32_t get_texel_from_image(mlx_image_t *image, const uint32_t tex_x, const uint32_t tex_y) {
//     // テクスチャの幅と高さを超えないようにするためのチェック
//     if (tex_x < 0 || tex_x >= image->width || tex_y < 0 || tex_y >= image->height)
//         return 0;  // 無効なピクセルを返す場合

//     // テクスチャのピクセル配列から指定位置の色を取得
//     int index = (tex_y * image->width + tex_x) * 4;  // RGBAの各要素は1バイト
//     uint8_t r = image->pixels[index];
//     uint8_t g = image->pixels[index + 1];
//     uint8_t b = image->pixels[index + 2];
//     uint8_t a = image->pixels[index + 3];

//     // 32ビットのカラー値として返す
//     return (a << 24) | (r << 16) | (g << 8) | b;
// }

void render_wall(t_cub3d *data, t_ray *ray, int x)
{
    int line_height = (int)(HEIGHT_WIN / ray->wall_dist);
    int draw_start = -line_height / 2 + HEIGHT_WIN / 2;
    if (draw_start < 0) draw_start = 0;
    int draw_end = line_height / 2 + HEIGHT_WIN / 2;
    if (draw_end >= HEIGHT_WIN) draw_end = HEIGHT_WIN - 1;

    double wall_x = ray->side == 0 ? data->player.pos_y + ray->wall_dist * ray->ray_dir_y
                                   : data->player.pos_x + ray->wall_dist * ray->ray_dir_x;
    wall_x -= floor(wall_x);

    // テクスチャ番号を取得し、適切なテクスチャを選択
    mlx_image_t *texture_img = NULL;
    if (ray->side == 0) {
        texture_img = ray->ray_dir_x > 0 ? data->textures.no_texture : data->textures.so_texture;
    } else {
        texture_img = ray->ray_dir_y > 0 ? data->textures.ea_texture : data->textures.we_texture;
    }

    if (!texture_img) {
        fprintf(stderr, "Failed to get texture image\n");
        return;
    }

    int tex_x = (int)(wall_x * (double)(texture_img->width));
    if (ray->side == 0 && ray->ray_dir_x > 0) tex_x = texture_img->width - tex_x - 1;
    if (ray->side == 1 && ray->ray_dir_y < 0) tex_x = texture_img->width - tex_x - 1;

    for (int y = draw_start; y < draw_end; y++) {
        int d = y * 256 - HEIGHT_WIN * 128 + line_height * 128;
        int tex_y = ((d * texture_img->height) / line_height) / 256;
        uint32_t color = get_texel_from_image(texture_img, tex_x, tex_y);
        mlx_put_pixel(data->map.img, x, y, color);
    }
}

uint32_t get_texel_from_image(mlx_image_t *image, const uint32_t tex_x, const uint32_t tex_y) {
    int index = (tex_y * image->width + tex_x) * 4;  // RGBの各要素は1バイト
    uint8_t r = image->pixels[index];
    uint8_t g = image->pixels[index + 1];
    uint8_t b = image->pixels[index + 2];
    uint8_t a = image->pixels[index + 3];
    return (a << 24) | (r << 16) | (g << 8) | b; 
}


void	draw_ceil_floor(t_cub3d *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < HEIGHT_WIN)
	{
		i = 0;
		while (i < WIDTH_WIN)
		{
			if (j < HEIGHT_WIN / 2)
				mlx_put_pixel(data->map.img, i, j, data->textures.sky_hex);
			else
				mlx_put_pixel(data->map.img, i, j, data->textures.floor_hex);
			i++;
		}
		j++;
	}
}
