/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:00:27 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/01 23:21:22 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

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
	int		i;
	int		j;
	unsigned int pixel;
	
	//Frame Size
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

void	render(t_window *game)
{
	char	c;
	int		h;
	int		w;


	ft_printf("%d %d\n", game->map.player_x, game->map.player_y);
	frame_to_frame(&(game->fon_img), &(game->frame), 0, 0);
	h = 0;
	while (h < game->map.height)
	{
		w = 0;
		while (w < game->map.width)
		{
			c = game->map.map[h][w];
			if (c == '1')
				frame_to_frame(&(game->wall_img), &(game->frame), w*64, h*64);
			else if(c == 'C')
				frame_to_frame(&(game->countable_img), &(game->frame), w*64, h*64);
			else if(c == 'E')
				frame_to_frame(&(game->exit_img), &(game->frame), w*64, h*64);
			else if(c == 'P')
				frame_to_frame(&(game->hero_img), &(game->frame), w*64, h*64);
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(game->mlx, game->display, game->frame.img, 0, 0);
}
