/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 01:13:37 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/12 00:09:50 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error_handler(char *error)
{
	ft_putstr_fd(error, 2);
	exit(0);
}


int main(int argc, char **argv)
{
	t_game  game;

	if (!argc || !*argv)
		return (0);

	// Загрузка карты
	game.map = read_map((t_game *)&game, (char *)"maps/Agate-Satellite.ber");
	// Анализ карты
	analyze_map((t_game *)&game);
	// Создание окна
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, 1280, 960, "Game");
	// Хуки
	mlx_key_hook(game.window, key_hook, &game);
	// Загрузка картинок
	load_images((t_game *)&game);
	// Рендер
	render((t_game *)&game);
	// render(game);

	// mlx_key_hook(game->display, key_hook, (void*)game);
	mlx_loop(game.mlx);
}
