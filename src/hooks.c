/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 21:10:59 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/13 19:45:23 by cchekov          ###   ########.fr       */
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
    {
        game->map_countables--;
        game->player_countables++;
    }
    else if (place_turn == 'E' && game->map_countables == 0)
    {
        ft_printf("Player made %d steps and collect %d coins \nYOU WIN", game->player_steps, game->player_countables);
        game_clean(game);
        exit(0);
    }
    else if (place_turn == 'E' && game->map_countables != 0)
        return ;
    
    game->map[game->map_player_y][game->map_player_x] = '0';
    game->map[y][x] = 'P';
    game->map_player_x = x;
    game->map_player_y = y;
    game->player_steps += 1;
    ft_printf("Step %d\n", game->player_steps);
}

int	end_hook(void *data)
{
    t_game   *game;

    game = (t_game *)data;
    ft_printf("Player made %d steps and collect %d coins \nGame Exit",  game->player_steps, game->player_countables);
    game_clean(game);
    exit(0);
    
    return (0);
}


int	key_hook(int keycode, void *data)
{
    t_game   *game;

    game = (t_game *)data;
    if (keycode == 0)
        make_turn(game, game->map_player_x - 1, game->map_player_y);
    else if (keycode == 2)
        make_turn(game, game->map_player_x + 1, game->map_player_y);
    else if (keycode == 1)
        make_turn(game, game->map_player_x, game->map_player_y + 1);
    else if (keycode == 13)
        make_turn(game, game->map_player_x, game->map_player_y - 1);
    else if (keycode == 53)
    {
        ft_printf("Player made %d steps and collect %d coins \nGame Exit",  game->player_steps, game->player_countables);
        game_clean(game);
        exit(0);
    }
        

    return (0);
}

