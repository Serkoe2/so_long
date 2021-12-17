/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 01:13:37 by cchekov           #+#    #+#             */
/*   Updated: 2021/12/12 16:50:31 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void error_handler(char *error)
{
	ft_putstr_fd(error, 2);
	exit(0);
}

t_sett_obj set_handler(int width, int height, char *name, int x, int y)
{
	t_sett_obj set;
	
	set.width = width;
	set.height = height;
	set.name = name;
	set.x = x;
	set.y = y;
	return set;
}

int main()
{
	void	*mlx;
	void	*window;
	int		red;
	int 	fd;
	t_window *game;
	t_sett_obj set;

	red = 0x00FF0000;
	//game = create_main(1024, 768, 'F');
	//game = create_wth_mlx_main('F');
	game = create_main(800, 600, 'F');
	read_map(game, (char *)"maps/Amber-Planet.ber");
	view_map(game->map);
//  init_objects(game);
//	view_objects(game->objects);
	//return 0;
//	return 0;
//	game = create_main(800, 600, 'F');
// /* -------- add objs --------- */
// 	set = set_handler(1, 1, "player", 0, 50);
// 	game->player = create_fill_rect(game, set, red);
// 	view_objects(game->objects);
// /* -------- add hooks --------- */
// 	mlx_key_hook(game->display, key_hook, game);
// 	render(game);
 	mlx_loop(game->mlx);
}
