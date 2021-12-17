/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 01:13:37 by cchekov           #+#    #+#             */
/*   Updated: 2021/12/16 18:05:00 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void error_handler(char *error)
{
	ft_putstr_fd(error, 2);
	exit(0);
}


int main()
{
	int		red;
	int		i;
	t_window *game;

	game = create_main(800, 600);
	i = 0;
	read_map(game, (char *)"maps/Agate-Satellite.ber");
	view_map(game->map);
	render(game);
	mlx_key_hook(game->display, key_hook, game);
 	mlx_loop(game->mlx);
}
