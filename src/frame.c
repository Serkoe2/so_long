/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:00:27 by cchekov           #+#    #+#             */
/*   Updated: 2021/12/16 20:34:11 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	put_pixel_to_frame(t_frame *frame, int x, int y, int color)
{
	char	*dst;
	
	dst = frame->addr + (y * frame->line_length + x * (frame->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/* Put all game objects from map to game->frame */
void	render(t_window *game)
{
	char	c;
	int		h;
	int		w;
	int		color;
	printf("%d %d\n", game->map.player_x, game->map.player_y);
	h = 0;
	while (h < game->map.height)
	{
		w = 0;
		while (w < game->map.width)
		{
			color = 0x00000000;
			c = game->map.map[h][w];
			if (c == '1')
				color = 0x00FF0000;
			else if(c == 'C')
				color = 0x000000FF;
			else if(c == 'E')
				color = 0x0000FF00;
			else if(c == 'P')
				color = 0x00ABBCCBB;
			create_fill_square(game, color, w * game->scale, h * game->scale);
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(game->mlx, game->display, game->frame.img, 0, 0);
	view_map(game->map);
}
