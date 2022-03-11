/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 21:10:59 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/12 00:24:37 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void make_turn(t_game *game, int x, int y)
{
    char    place_turn;

    if (x < 1 || y < 1)
        return ;
    place_turn = game->map[y][x];
    if (place_turn == '1')
        return ;
    else if (place_turn == 'C')
        game->map_countables--;
    else if (place_turn == 'E' && game->map_countables == 0)
        error_handler("YOU WIN");
    else if (place_turn == 'E' && game->map_countables != 0)
        return ;
    
    game->map[game->map_player_y][game->map_player_x] = '0';
    game->map[y][x] = 'P';
    game->map_player_x = x;
    game->map_player_y = y;
}

// Неправильно читается x/y
int	key_hook(int keycode, void *data)
{
    // void	*buf;
    t_game   *game;

    game = (t_game *)data;
    // main = (t_window *)q;
    // printf("KEY HOOK %p \n",  &(main->map));
    ft_printf("Hello from key_hook! %d\n", keycode);
    view_map(game->map);
    // printf("My map\n");
	// view_map(&(main->map));
	
    if (keycode == 123)
        make_turn(game, game->map_player_x - 1, game->map_player_y);
    // else if (keycode == 124)
    //     make_turn(&(main->map), main->map.player_x + 1, main->map.player_y);
    // else if (keycode == 125)
    //     make_turn(&(main->map), main->map.player_x, main->map.player_y + 1);
    // else if (keycode == 126)
    //     make_turn(&(main->map), main->map.player_x, main->map.player_y - 1);
    //mlx_clear_window(main->mlx, main->display);
    // create_fill_square(&(main->frame), 0x0, 0, 0);
    //render(main);
    return (0);
}
