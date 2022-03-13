/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:30:58 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/13 17:45:00 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	view_map(char **map)
{
	int i;

	i = 0;
	while (map[i][0])
	{
		ft_printf("VIEW MAP %p %s\n", map[i], map[i]);
		i++;
	}
}

char	**load_map(int fd, char **map, t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{	
		map[i] = ft_strdup((const char *)line);
		free(line);
		if (!map[i])
			error_handler("MALLOC ERROR", game);
		line = get_next_line(fd);
		i++;
	}
	
	return (map);
}

int		count_line(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{	
		line = get_next_line(fd);
		free(line);
		i++;
	}
	
	return (i);
}

char   **read_map(t_game *game, char *name)
{
    int		fd;
	int		lines;
	char	**map;

    fd = open(name, O_RDONLY);
    if (fd < 2)
        error_handler("FILE ERROR", NULL);
	lines = count_line(fd);
	close(fd);
	if (!lines)
		error_handler("MAP HEIGHT ERROR", NULL);
	map = (char **)ft_calloc(lines, sizeof(char **));
	if (!map)
		error_handler("MALLOC ERROR", NULL);
	game->map = map;
	game->map_height =  lines;
	fd = open(name, O_RDONLY);
    if (fd < 2)
        error_handler("FILE ERROR", game);
	map = load_map(fd, map, game);
	close(fd);
	game->map_width = ft_strlen(map[0]);
	if (!game->map_width)
		error_handler("MAP WIDTH ERROR", game);
	return map;
}