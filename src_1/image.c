/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:23:52 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/12 14:25:59 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file(char *name)
{
	int	fd;

	fd = open(name, O_RDONLY);
    if (fd < 2)
        error_handler("FILE ERROR");
	close(fd);
}

t_frame   *load_image(t_game *game, char *name)
{	
    t_frame	*img;

	img = NULL;
	check_file(name);
	img = (t_frame *)ft_calloc(1, sizeof(t_frame));

	img->img = mlx_xpm_file_to_image(game->mlx, name, &(img->width), &(img->height));

	if (!img->img)
	    error_handler("XPM LOAD FAIL");
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),  &(img->line_length), &(img->endian));
	return img;
}


void    load_images(t_game *game)
{
    t_frame	 *img;
    
	game->bg_img = load_image(game, (char *)"./assets/bg.xpm");
	game->wall_img = load_image(game, (char *)"./assets/walls.xpm");
	game->hero_img = load_image(game, (char *)"./assets/hero.xpm");
	game->countable_img = load_image(game, (char *)"./assets/countables.xpm");
	game->exit_img = load_image(game, (char *)"./assets/exit.xpm");
	

    img = (t_frame *)malloc(sizeof(t_frame));
    img->img = mlx_new_image(game->mlx, 1280, 960);
	if (!img->img)
	    error_handler("MAIN FRAME FAIL");
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),  &(img->line_length), &(img->endian));
	game->main = img;
}