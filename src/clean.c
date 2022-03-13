/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:52:48 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/13 15:48:17 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_frame(t_game *game, t_frame *frame)
{
	if (!frame)
		return ;
	mlx_destroy_image(game->mlx, frame->img);
	free(frame);
}

// Может падать если строка еще не замалоченна
void	clean_map(t_game *game)
{
	int	i;

	if (!game->map)
		return ;
	i = 0;
	while (i < game->map_height)
		free(game->map[i++]);
	free(game->map);
}

void	game_clean(t_game *game)
{
    clean_map(game);
	clean_frame(game, game->hero_img);
	clean_frame(game, game->wall_img);
	clean_frame(game, game->countable_img);
	clean_frame(game, game->exit_img);
	clean_frame(game, game->bg_img);
	clean_frame(game, game->main);
	if (!game->mlx || !game->window)
		return ;
	mlx_destroy_window(game->mlx, game->window);
}