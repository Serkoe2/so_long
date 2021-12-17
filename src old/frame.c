/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:00:27 by cchekov           #+#    #+#             */
/*   Updated: 2021/11/16 05:33:38 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	put_pixel_to_frame(t_frame *frame, int x, int y, int color)
{
	char	*dst;

	dst = frame->addr + (y * frame->line_length + x * (frame->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	render(t_window *main)
{
	t_frame *frame;
	t_list	*obj;

	obj = main->objects;
	while (obj)
	{
		frame = (t_frame *)obj->content;
		mlx_put_image_to_window(main->mlx, main->display, frame->img, frame->x, frame->y);
		obj = obj->next;
	}
	printf("FINISH RENDER\n");
}

int		count_width(char **map, int w, int h)
{
	int i;

	i = 0;
	while (map[h][w + i] == '1')
		i++;
	return (i - 1);
}
void	init_objects(t_window *main)
{
	// функция должна выполнить поиск объектов по массиву
	// действуем без рамки, поэтому старт от 1
	int 		h;
	int 		w;
	int 		c;
	int			count;
	t_sett_obj 	set;
	
	set =  set_handler(main->map.width, main->map.height, "border", 0, 0);
	set.color = 0x00FF0000;
	create_stroke_rect(main, set);
	
	h = 1;
	while (h < main->map.height - 1)
	{
		w = 1;
		while (w < main->map.width - 1)
		{
			c = main->map.map[h][w];
			if (c == '1')
			{
				count = count_width(main->map.map, w, h);
				set =  set_handler(count, 1, "wall", w, h);
				set.color = 0x00FF0000;
				create_fill_rect(main, set);
				w = w + count;
			}
			else if(c == 'C'){
				set =  set_handler(1, 1, "countable", w, h);
				set.color = 0x000000FF;
				create_fill_rect(main, set);
			} 
			else if(c == 'E'){
				set =  set_handler(1, 1, "exit", w, h);
				set.color = 0x0000FF00;
				create_fill_rect(main, set);
			}
			else if(c == 'P'){
				set =  set_handler(1, 1, "player", w, h);
				set.color = 0x00ABBCCBB;
				create_fill_rect(main, set);
			}
			w++;
		}
		h++;
	}
	printf("-----------------\n");
}
// Объединение объектов в текстуры ?