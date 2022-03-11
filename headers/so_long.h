/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 01:13:33 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/10 21:30:52 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include "../libft/libft.h"
// #include "../ft_printf/ft_printf.h"
#include "../gnl/get_next_line.h"
#include <stdio.h>

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
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_frame;


typedef struct	s_map
{
	int	width;
	int	height;
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
	t_frame		hero_img;
	t_frame		wall_img;
	t_frame		countable_img;
	t_frame		exit_img;
	t_frame		fon_img;
	t_frame		frame;
	t_map		map;
}				t_window;

void	error_handler(char *error);
t_sett_obj set_handler(int width, int height, char *name, int x, int y);
void	put_pixel_to_frame(t_frame *frame, int x, int y, int color);
void	create_fill_square(t_frame *frame, int color,  int x, int y);
t_frame	*create_fill_rect(t_window *main, t_sett_obj set);
t_frame	*create_stroke_rect(t_window *main, t_sett_obj set);

t_window	*create_main(int width, int height);
t_frame 	*create_object(t_window *main, t_sett_obj set);

/*----------- view ----------*/
void		view_objects(t_list *list);
void		view_map(t_map *map);

/*----------- hooks ----------*/
int	key_hook(int keycode, void *q);
/*----------- map ------------*/
void		read_map(t_window *main, char *name);
t_window 	*create_wth_mlx_main(char mode);

void		render(t_window *game);
void		init_objects(t_window *main);
#endif