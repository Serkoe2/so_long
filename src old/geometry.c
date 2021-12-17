/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:18:43 by cchekov           #+#    #+#             */
/*   Updated: 2021/12/12 16:51:56 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

t_frame	*create_fill_rect(t_window *main, t_sett_obj set)
{
	int		w;
	int		h;
	t_frame *frame;
 
	frame = create_object(main, set);
	h = frame->height;
	while (h)
	{
		w = frame->width;
		while(w)
		{
			put_pixel_to_frame(frame, w, h, set.color);
			w--;
		}
		h--;
	}
	return frame;
}

//void    stroke_rect(t_frame *frame, int width, int height, int color)
t_frame		*create_stroke_rect(t_window *main, t_sett_obj set)
{
	int	w;
	int h1;
	int i;
	t_frame *frame;
	
	frame = create_object(main, set);
	h1 = frame->height;
	while (h1)
	{
		w = frame->width;
		if (h1 >= frame->height - main->scale || h1 <= 1 + main->scale)
		{
			while(w)
			{
				put_pixel_to_frame(frame, w, h1, set.color);
				w--;
			}
		}
		else
		{
			i = main->scale;
			while (i)
			{
				put_pixel_to_frame(frame, i, h1, set.color);
				put_pixel_to_frame(frame, w - i, h1, set.color);
				i--;
			}
		}
		h1--;
	}
	return frame;
}
