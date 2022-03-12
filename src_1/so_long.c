/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 01:13:37 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/12 13:36:02 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error_handler(char *error)
{
	ft_printf("Error\n%s\n", error);
	// Память чистить сколько
	exit(0);
}

char	*check_filename(char **argv)
{
	char	*test;
	size_t	len;

	if (!*argv || !**argv)
		error_handler("MAP NAME NOT FOUND IN ARG");
	test = *argv;
	len = ft_strlen(test);
	if (len < 5)
		error_handler("MAP NAME NOT FOUND IN ARG");
	test = test + len - 4;
	if (ft_strncmp((const char *)test, ".ber", 4))
		error_handler("MAP EXTENSION MUST BE .ber");
	return (*argv);
}

int main(int argc, char **argv)
{
	t_game  game;

	if (argc != 2)
		error_handler("MAP NAME NOT FOUND IN ARG");
	// check_filename(argv);
	// Загрузка карты
	game.map = read_map((t_game *)&game, check_filename(++argv));
	// Анализ карты
	analyze_map((t_game *)&game);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, 1280, 960, "Game");
	// Загрузка картинок
	load_images((t_game *)&game);
	// Хуки
	mlx_loop_hook(game.mlx, render, &game);
	mlx_hook(game.window, 2, 0, key_hook, &game);
	mlx_hook(game.window, 17, 0, end_hook, &game);
	// mlx_key_hook(game->display, key_hook, (void*)game);
	mlx_loop(game.mlx);
}
