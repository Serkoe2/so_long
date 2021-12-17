/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:18:43 by cchekov           #+#    #+#             */
/*   Updated: 2021/12/12 23:46:39 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	create_fill_square(t_window *main, int color, int x, int y)
{
	int	h;
	int w;
	
	h = main->scale;
	while (h)
	{
		w = main->scale;
		while(w)
		{
			put_pixel_to_frame(&(main->frame), x + w, y + h, color);
			w--;
		}
		h--;
	}
}
