/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:43:46 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/12 13:12:45 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	test_values(t_game *game)
{
	int		i;
	int		j;
	char	temp;
	int 	must_val_E;
	int 	must_val_P;
	
	i = game->map_height - 1;
	must_val_E = 0;
	must_val_P = 0;
	while (i >= 0)
	{
		j = game->map_width - 1;
		while (j >= 0)
		{
			temp = game->map[i][j];
			if (!ft_strchr("01CEP", temp))
				error_handler("MAP VALUES ERROR");
			if (temp == 'C')
				game->map_countables++;
			else if(temp == 'E')
				must_val_E++;
			else if (temp == 'P')
			{
				must_val_P++;
				game->map_player_x = j;
				game->map_player_y = i;
			}
			j--;
		}
		i--;
	}
	if ( must_val_E != 1)
		error_handler("MAP VALUES ERROR: EXIT UNCORRECT");
	if ( must_val_P != 1)
		error_handler("MAP VALUES ERROR: PLAYER UNCORRECT");
	if ( game->map_countables == 0)
		error_handler("MAP VALUES ERROR: COUNTABLES NO ONE");
}

void	test_border(t_game *game)
{
	int	i;
	int j;
	
	i = game->map_height - 1;
	j = 0;
	while (j < game->map_width)
	{
		if (game->map[0][j] != '1')
			error_handler("MAP FIRST ROW ERROR");
		if (game->map[i][j] != '1')
			error_handler("MAP LAST ROW ERROR");
		j++;
	}
	j = game->map_width - 1;
	while (i)
	{
		if (game->map[i][0] != '1' || game->map[i][j] != '1')
			error_handler("MAP ROW ERROR");
		i--;
	}
}

void	test_width(t_game *game)
{
	int	i;
	
	i = 0;
	while (i < game->map_height)
		if (ft_strlen(game->map[i++]) != (unsigned int)game->map_width)
			error_handler("MAP WIDTH ERROR");
}

void	analyze_map(t_game *game)
{
	test_width(game);
	test_border(game);
	test_values(game);
}