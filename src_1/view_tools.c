/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:34:44 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/01 22:49:14 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	view_objects(t_list *list)
{
	t_frame *frame;
	
	if (!list)
		return ;
	while (list)
	{
		frame = (t_frame *)list->content;
		ft_printf("OBJECT -  pointer %p\n", frame->img);
		list = list->next;
	}
}

void	view_map(t_map map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map.height)
	{
		write(1, map.map[i], map.width);
		write(1, "\n", 1);
		i++;
	}
}