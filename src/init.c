/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 21:12:02 by cchekov           #+#    #+#             */
/*   Updated: 2022/01/10 04:51:38 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	create_fill_square(t_frame *frame, int color, int x, int y)
{
	int	h;
	int w;
	
	h = y;
	while (h > 0)
	{
		w = x;
		while(w > 0)
		{
			put_pixel_to_frame(frame, w, h, color);
			w--;
		}
		h--;
	}
}

t_frame   *load_image(t_window *main, char *name)
{	
    t_frame	*img;

	img = (t_frame *)malloc(sizeof(t_frame));
	img->img = mlx_xpm_file_to_image(main->mlx, name, &(img->width), &(img->height));
	if (!img->img)
	    error_handler("XPM LOAD FAIL");
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),  &(img->line_length), &(img->endian));
	return img;
}


void    load_images(t_window *main)
{
    t_frame	 img;
    
	main->hero_img = *load_image(main, "./assets/hero.xpm");
	main->wall_img = *load_image(main, "./assets/walls.xpm");
	main->countable_img = *load_image(main, "./assets/countables.xpm");
	main->exit_img = *load_image(main, "./assets/exit.xpm");
	img.img = mlx_new_image(main->mlx, main->width, main->height);
	if (!img.img)
	    error_handler("Fon XPM FAIL");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,  &img.line_length, &img.endian);
	create_fill_square(&img, 0x00000000, main->width - 1, main->height - 1);
	main->fon_img = img;
	main->fon_img.width = main->height;
	main->fon_img.height = main->width;
}

t_window *create_main(int width,int height)
{
    t_window    *main;
	
    main = (t_window *)malloc(sizeof(t_window));
    main->mlx = mlx_init();
    main->display = mlx_new_window(main->mlx, width, height, "Game");
    main->frame.img =  mlx_new_image(main->mlx, width, height);
    main->frame.addr = mlx_get_data_addr(main->frame.img, &main->frame.bits_per_pixel, &main->frame.line_length, &main->frame.endian);
    main->width = width;
    main->height = height;
    main->map.countables = 0;
    load_images(main);
    return (main);
}