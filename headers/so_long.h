/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 01:13:33 by cchekov           #+#    #+#             */
/*   Updated: 2021/12/16 18:34:28 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

typedef struct	s_sett_obj
{
	char	*name;
	int		color;
	int		x;
	int		y;
	int		width;
	int		height;
}				t_sett_obj;

typedef struct	s_frame
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*name;
	int		x;
	int		y;
	int		width;
	int		height;
}				t_frame;


typedef struct	s_map
{
	unsigned int	width;
	unsigned int	height;
	unsigned int	countables;
	int				player_x;
	int				player_y;
	char			**map;
}				t_map;

typedef struct	s_window
{
	int			width;
	int			height;
	int			scale;
	void		*display;
	void		*mlx;
	t_frame		frame;
	t_map		map;
}				t_window;

void	error_handler(char *error);
t_sett_obj set_handler(int width, int height, char *name, int x, int y);
void	put_pixel_to_frame(t_frame *frame, int x, int y, int color);
void	create_fill_square(t_window *main, int color,  int x, int y);
t_frame	*create_fill_rect(t_window *main, t_sett_obj set);
t_frame	*create_stroke_rect(t_window *main, t_sett_obj set);

t_window	*create_main(int width, int height);
t_frame 	*create_object(t_window *main, t_sett_obj set);

/*----------- view ----------*/
void		view_objects(t_list *list);
void		view_map(t_map map);

/*----------- hooks ----------*/
int	key_hook(int keycode, t_window *main);
/*----------- map ------------*/
void		read_map(t_window *main, char *name);
t_window 	*create_wth_mlx_main(char mode);

void		render(t_window *game);
void		init_objects(t_window *main);
#endif