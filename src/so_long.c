/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 01:13:37 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/10 21:24:33 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void error_handler(char *error)
{
	ft_putstr_fd(error, 2);
	exit(0);
}


int main(int argc, char **argv)
{
	int		i;
	t_window *game;

	if (!argc || !*argv)
		return (0);
	game = create_main(1280, 960);
	i = 0;
	read_map(game, (char *)"maps/Agate-Satellite.ber");
	//render(game); 
	//mlx_key_hook(game->display, key_hook, (void*)game);
	printf("MAIN %p\n", &(game->map));
	mlx_key_hook(game->display, key_hook, (void *)game);
 	mlx_loop(game->mlx);
}
