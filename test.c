#include "mlx/mlx.h"
#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

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

/* -------------------------- */
void error_handler(char *error)
{
	ft_putstr_fd(error, 2);
	exit(0);
}

/* Первая ошибка здесь */
void	load_to_array(char **map, t_list *list)
{
	int		i;

	i = 0;
	while (list)
	{
		map[i] = ft_strdup((const char *)list->content);
		if (!map[i])
			error_handler("AAAAA");
		list = list->next;
		i++;
	}
}

void	read_file2(int fd, t_map *el)
{
	t_list	*temp;
	t_list	*list;
	char	*line;
	char	**map;

	list = NULL;
	el->height = 0;
	line = get_next_line(fd);
	while (line)
	{
		el->height++;
		temp = ft_lstnew((void *)line);
		if (!temp)
			error_handler("LIST ERROR");
		ft_lstadd_back(&list, temp);
		line = get_next_line(fd);
	}
	if (!el->height)
		error_handler("FILE MAP ERROR");
	map = (char **)malloc(el->height);
	if (!map)
		error_handler("MAP CREATE ERROR");
	
	load_to_array(map, list);
	return ;
	el->width = ft_strlen(map[0]);
	el->map = map;
}

void	read_file(int fd, t_map *el)
{
	t_list	*temp;
	t_list	*list;
	char	*line;
	char	**map;

	list = NULL;
	el->height = 0;
	line = get_next_line(fd);
	while (line)
	{
		el->height++;
		temp = ft_lstnew((void *)line);
		if (!temp)
			error_handler("LIST ERROR");
		ft_lstadd_back(&list, temp);
		line = get_next_line(fd);
	}
	if (!el->height)
		error_handler("FILE MAP ERROR");
	map = (char **)malloc(el->height);
	if (!map)
		error_handler("MAP CREATE ERROR");
	
	load_to_array(map, list);
	ft_lstclear(&list, free);
	el->map = map;
	return ;
	el->width = ft_strlen(map[0]);
}

void    read_map(t_window *main, char *name)
{
    int		fd;
	t_window q;
	q = *main;
    fd = open(name, O_RDONLY);
    if (fd < 2)
        error_handler("FILE ERROR");
	
	read_file(fd, &(main->map));
	close(fd);
	// analyze_map(&(main->map));
}

void	create_fill_square(t_frame *data, int color, int x, int y)
{
	int					h;
	int 				w;
	char	 *dst;
	
	h = y;
	while (h > 0)
	{
		w = x;
		while(w > 0)
		{
			dst = data->addr + y * data->line_length + x * (data->bits_per_pixel / 8);
			*dst = color;
			w--;
		}
		h--;
	}
}

t_frame   *load_image(t_window *main, char *name)
{	
    t_frame	*img;

	img = (t_frame *)malloc(sizeof(t_frame));
	img->img = mlx_xpm_file_to_image(main->mlx, name, &(img->width), &(img->height));
	if (!img->img)
	    error_handler("XPM LOAD FAIL");
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),  &(img->line_length), &(img->endian));
	return img;
}

void    load_images(t_window *main)
{
    t_frame	 img;
    
	main->hero_img = *load_image(main, "./assets/hero.xpm");
	main->wall_img = *load_image(main, "./assets/walls.xpm");
	main->countable_img = *load_image(main, "./assets/countables.xpm");
	main->exit_img = *load_image(main, "./assets/exit.xpm");
	img.img = mlx_new_image(main->mlx, main->width, main->height);
	if (!img.img)
	    error_handler("Fon XPM FAIL");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,  &img.line_length, &img.endian);
	create_fill_square(&img, 0x00000000, main->width - 1, main->height - 1);
	main->fon_img = img;
	main->fon_img.width = main->height;
	main->fon_img.height = main->width;
}

t_window *create_main(int width,int height)
{
    t_window    *main;
	
    main = (t_window *)malloc(sizeof(t_window));
    main->mlx = mlx_init();
    main->display = mlx_new_window(main->mlx, width, height, "Game");
    main->frame.img =  mlx_new_image(main->mlx, width, height);
    main->frame.addr = mlx_get_data_addr(main->frame.img, &main->frame.bits_per_pixel, &main->frame.line_length, &main->frame.endian);
    main->width = width;
    main->height = height;
    main->map.countables = 0;
    load_images(main);
    return (main);
}

int	main(void)
{
	t_window *game;

	game = create_main(1280, 960);
	read_map(game, (char *)"maps/Agate-Satellite.ber");
	mlx_loop(game->mlx);
}