/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:39:39 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/12 14:26:13 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	put_pixel_to_frame(t_frame *frame, int x, int y, int color)
{
	char	*dst;
	
	dst = frame->addr + (y * frame->line_length + x * (frame->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int		pull_pixel_frame(t_frame *frame, int x, int y)
{
	char	*dst;
	
	dst = frame->addr + (y * frame->line_length + x * (frame->bits_per_pixel / 8));
	return *(unsigned int*)dst;
}

void	frame_to_frame(t_frame *from, t_frame *to, int x, int y)
{
	int		        i;
	int		        j;
	unsigned int    pixel;
	
	i = 0;
	while (i < from->height)
	{
		j = 0;
		while (j < from->width)
		{
			pixel = pull_pixel_frame(from, i, j);
			put_pixel_to_frame(to, x + i, y + j, pixel);
			j++;
		}
		i++;
	}
}

int		render(void *data)
{
	char	c;
	int		h;
	int		w;
    int     scale;
	t_game	*game;

	game = (t_game *)data;
	h = 0;
    scale = 64;
	while (h < game->map_height)
	{
		w = 0;
		while (w < game->map_width)
		{
			c = game->map[h][w];
			if (c == '1')
				frame_to_frame(game->wall_img, game->main, w*scale, h*scale);
			else if(c == 'C')
				frame_to_frame(game->countable_img, game->main, w*scale, h*scale);
			else if(c == 'E')
				frame_to_frame(game->exit_img, game->main, w*scale, h*scale);
			else if(c == 'P')
				frame_to_frame(game->hero_img, game->main, w*scale, h*scale);
			else if(c == '0')
				frame_to_frame(game->bg_img, game->main, w*scale, h*scale);
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->main->img, 0, 0);
	return (0);
}