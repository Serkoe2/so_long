/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 01:13:37 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/13 19:20:10 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error_handler(char *error, t_game *game)
{
	ft_printf("Error\n%s\n", error);
	if (game)
		game_clean(game);
	exit(0);
}

void	init(t_game *game)
{
	game->player_steps = 0;
	game->player_countables = 0;
	game->window = NULL;
	game->mlx = NULL;
	game->map = NULL;
	game->hero_img = NULL;
	game->wall_img = NULL;
	game->countable_img = NULL;
	game->exit_img = NULL;
	game->bg_img = NULL;
	game->main = NULL;
}

char	*check_filename(char **argv)
{
	char	*test;
	size_t	len;

	if (!*argv || !**argv)
		error_handler("MAP NAME NOT FOUND IN ARG", NULL);
	test = *argv;
	len = ft_strlen(test);
	if (len < 5)
		error_handler("MAP NAME NOT FOUND IN ARG", NULL);
	test = test + len - 4;
	if (ft_strncmp((const char *)test, ".ber", 4))
		error_handler("MAP EXTENSION MUST BE .ber", NULL);
	return (*argv);
}

int main(int argc, char **argv)
{
	t_game  game;

	if (argc != 2)
		error_handler("MAP NAME NOT FOUND IN ARG", NULL);
	init((t_game *)&game);
	game.map = read_map((t_game *)&game, check_filename(++argv));
	analyze_map((t_game *)&game);
	game.player_steps = 0;
	if (game.map_width > 100 || game.map_height > 100)
		error_handler("MAP IS TOO LONG", (t_game *)&game);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.window_width, game.window_height, "Game");
	load_images((t_game *)&game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_hook(game.window, 2, 0, key_hook, &game);
	mlx_hook(game.window, 17, 0, end_hook, &game);
	mlx_loop(game.mlx);
}
