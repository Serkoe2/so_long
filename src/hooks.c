/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 21:10:59 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/01 23:37:26 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void make_turn(t_map *map, int x, int y)
{
    char    place_turn;

    ft_printf("PLAYER_X %d\nPLAYER_Y %d\nF_X %d\nF_Y %d \n",map->player_x, map->player_y, x, y);
    if (x < 1 || y < 1)
        return ;
    place_turn = map->map[y][x];
    if (place_turn == '1')
        return ;
    else if (place_turn == 'C')
        map->countables--;
    else if (place_turn == 'E' && map->countables == 0)
        error_handler("YOU WIN");
    else if (place_turn == 'E' && map->countables != 0)
        return ;
    
    map->map[map->player_y][map->player_x] = '0';
    map->map[y][x] = 'P';
    map->player_x = x;
    map->player_y = y;
}

int	key_hook(int keycode, void *q)
{
    t_window    *main;

    main = (t_window*) q;
	ft_printf("Hello from key_hook! %d\n", keycode);
    ft_printf("My map\n");
	view_map(main->map);
	
    if (keycode == 123)
        make_turn(&(main->map), main->map.player_x - 1, main->map.player_y);
    else if (keycode == 124)
        make_turn(&(main->map), main->map.player_x + 1, main->map.player_y);
    else if (keycode == 125)
        make_turn(&(main->map), main->map.player_x, main->map.player_y + 1);
    else if (keycode == 126)
        make_turn(&(main->map), main->map.player_x, main->map.player_y - 1);
    mlx_clear_window(main->mlx, main->display);
    // create_fill_square(&(main->frame), 0x0, 0, 0);
    render(main);
    return (0);
}

