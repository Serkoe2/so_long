/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:30:58 by cchekov           #+#    #+#             */
/*   Updated: 2021/12/16 18:39:53 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"


// Первичный анализ - все строки одинакового размера
// Допустимые 0,1,C,E,P
// Must have C,E,P
// Необязательно проверять валидный путь на карте!

void	load_to_array(char **map, t_list *list)
{
	int		i;
	t_list	*temp;

	i = 0;
	while (list)
	{
		map[i] = (char *)list->content;
		temp = list;
		list = list->next;
		free(temp);
		i++;
	}
}

void	read_file(int fd, t_map *el)
{
	t_list	*temp;
	t_list	*list;
	char	*line;
	char	**map;
	int		count;

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
	el->width = ft_strlen(map[0]);
	el->map = map;
}

void	analyze_map(t_map *map)
{
	int 	i;
	int 	j;
	char	temp;
	int 	must_val_E;
	int 	must_val_P;

	must_val_E = 0;
	must_val_P = 0;
	i = 0;
	// test width
	while (i < map->height)
		if (ft_strlen(map->map[i++]) != map->width)
			error_handler("MAP WIDTH ERROR");
	// test map_border
	i = map->height - 1;;
	j = 0;
	while (j < map->width)
	{
		if (map->map[0][j] != '1')
			error_handler("MAP FIRST ROW ERROR");
		if (map->map[i][j] != '1')
			error_handler("MAP LAST ROW ERROR");
		j++;
	}
	i =  map->height - 1;
	j = map->width - 1;
	while (i)
	{
		if (map->map[i][0] != '1' || map->map[i][j] != '1')
			error_handler("MAP ROW ERROR");
		i--;
	}
	// test map values
	i =  map->height - 1;
	while (i >= 0)
	{
		j = map->width - 1;
		while (j >= 0)
		{
			temp = map->map[i][j];
			if (!ft_strchr("01CEP", temp))
				error_handler("MAP VALUES ERROR");
			if (temp == 'C')
				map->countables++;
			else if(temp == 'E')
				must_val_E++;
			else if (temp == 'P')
			{
				must_val_P++;
				map->player_x = j;
				map->player_y = i;
			}
			j--;
		}
		i--;
	}
	if ( must_val_E != 1)
		error_handler("MAP VALUES ERROR: EXIT UNCORRECT");
	if ( must_val_P != 1)
		error_handler("MAP VALUES ERROR: PLAYER UNCORRECT");
	if ( map->countables == 0)
		error_handler("MAP VALUES ERROR: COUNTABLES NO ONE");
}

void    read_map(t_window *main, char *name)
{
    int		fd;

    fd = open(name, O_RDONLY);
    if (fd < 2)
        error_handler("FILE ERROR");
	read_file(fd, &(main->map));
	close(fd);
	analyze_map(&(main->map));
}