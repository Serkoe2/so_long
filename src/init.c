/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 21:12:02 by cchekov           #+#    #+#             */
/*   Updated: 2021/12/12 23:53:23 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

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
    main->scale = 39;
    return (main);
}