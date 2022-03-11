/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:23:52 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/12 00:11:07 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_frame   *load_image(t_game *game, char *name)
{	
    t_frame	*img;

	img = (t_frame *)malloc(sizeof(t_frame));
	img->img = mlx_xpm_file_to_image(game->mlx, name, &(img->width), &(img->height));
	if (!img->img)
	    error_handler("XPM LOAD FAIL");
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),  &(img->line_length), &(img->endian));
	return img;
}


void    load_images(t_game *game)
{
    t_frame	 *img;
    
	game->hero_img = load_image(game, (char *)"./assets/hero.xpm");
	game->wall_img = load_image(game, (char *)"./assets/walls.xpm");
	game->countable_img = load_image(game, (char *)"./assets/countables.xpm");
	game->exit_img = load_image(game, (char *)"./assets/exit.xpm");
	
    img = (t_frame *)malloc(sizeof(t_frame));
    img->img = mlx_new_image(game->mlx, 1280, 960);
	if (!img->img)
	    error_handler("MAIN FRAME FAIL");
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),  &(img->line_length), &(img->endian));
	// create_fill_square(&img, 0x00000000, main->width - 1, main->height - 1);
	game->main = img;
	// main->fon_img.width = main->height;
	// main->fon_img.height = main->width;
}