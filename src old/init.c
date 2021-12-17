/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 21:12:02 by cchekov           #+#    #+#             */
/*   Updated: 2021/11/16 04:51:22 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

t_window *create_main(int width,int height, char mode)
{
    t_window    *main;

    main = (t_window *)malloc(sizeof(t_window));
    main->mlx = mlx_init();
    main->display = mlx_new_window(main->mlx, width, height, "Game");
    main->frame.img =  mlx_new_image(main->mlx, width, height);
    main->frame.addr = mlx_get_data_addr(main->frame.img, &main->frame.bits_per_pixel, &main->frame.line_length, &main->frame.endian);
    main->objects = NULL;
    main->width = width;
    main->height = height;
    main->memory.mem_alloc = 0;
    main->memory.mem_plank = 100000000;
    main->memory.mode = mode;
    main->memory.obj_count = 0;
    main->map.countables = 0;
    main->scale = 20;
    return (main);
}

t_window *create_wth_mlx_main(char mode)
{
    t_window    *main;

    main = (t_window *)malloc(sizeof(t_window));
    main->objects = NULL;
    main->memory.mem_alloc = 0;
    main->memory.mem_plank = 100000000;
    main->memory.mode = mode;
    main->memory.obj_count = 0;
    main->map.countables = 0;
    return (main);
}

t_frame *create_object(t_window *main, t_sett_obj set)
{
    t_frame *obj;
    t_list  *temp;
    int     count;

    count = 0;
    obj = (t_frame *)malloc(sizeof(t_window));
    if (!obj)
        error_handler("can't create frame object\n");
    obj->width = set.width * main->scale;
    obj->height = set.height * main->scale;
    obj->img = mlx_new_image(main->mlx, obj->width, obj->height);
    obj->addr = mlx_get_data_addr(obj->img, &obj->bits_per_pixel, &obj->line_length, &obj->endian);
    obj->name = set.name;
    obj->x = set.x * main->scale;
    obj->y = set.y * main->scale;
    if (!obj->img || !obj->addr)
        error_handler("can't create frame object's params\n");
    temp = ft_lstnew((void *)obj);
    if (!temp)
        error_handler("can't create list item\n");
    if (!main->objects)
        main->objects = temp;
    else
        ft_lstadd_back(&(main->objects), temp); 
    return obj;
    //printf("Obj %lu, Img %lu, Addr %lu\n",sizeof(obj), sizeof(obj->img), sizeof(obj->addr));
    //printf("Obj %lu, Img %lu, Addr %lu\n",sizeof(*obj), sizeof(*(obj->img)), sizeof(*(obj->addr)));
    // Пока непонятно как посчитать img и addr?? Указатели у них просто void и char - нужно понимать как объекты устроены!
}