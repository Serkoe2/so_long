/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 21:10:59 by cchekov           #+#    #+#             */
/*   Updated: 2021/12/13 00:07:05 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	key_hook(int keycode, t_window *main)
{
	printf("Hello from key_hook! %d\n", keycode);

    if (keycode == 123)
        main->player->x -= 25;
    else if (keycode == 124)
        main->player->x += 25;
    else if (keycode == 125)
        main->player->y += 25;
    else if (keycode == 126)
        main->player->y -= 25;
    mlx_clear_window(main->mlx, main->display);
    render(main);
    return (0);
}
