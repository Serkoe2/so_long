/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 01:13:33 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/13 17:57:52 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include "../gnl/get_next_line.h"

typedef struct	s_frame
{
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_frame;

typedef struct	s_game
{
	void		*window;
	int			window_width;
	int			window_height;
	void		*mlx;
	char		**map;
	int			map_width;
	int			map_height;
	int			map_countables;
	int			map_player_x;
	int			map_player_y;
	int			player_steps;
	t_frame		*hero_img;
	t_frame		*wall_img;
	t_frame		*countable_img;
	t_frame		*exit_img;
	t_frame		*bg_img;
	t_frame		*main;
}				t_game;


void	error_handler(char *error, t_game *game);
char    **read_map(t_game *game, char *name);
int		key_hook(int keycode, void *game);
void	view_map(char **map);
void	analyze_map(t_game *game);
void    load_images(t_game *game);
int		render(void *data);
int		end_hook(void *data);
void	game_clean(t_game *game);

#endif