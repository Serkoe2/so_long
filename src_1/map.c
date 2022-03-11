/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:30:58 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/11 22:55:00 by cchekov          ###   ########.fr       */
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

char	**load_map(int fd, char **map)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	map[i] = ft_strdup((const char *)line);
		if (!map[i])
			error_handler("MALLOC ERROR");
	while (line)
	{	
		i++;
		line = get_next_line(fd);
		map[i] = ft_strdup((const char *)line);
		if (!map[i])
			error_handler("MALLOC ERROR");
		free(line);
	}
	
	map[i] = ft_strdup("\0");
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
        error_handler("FILE ERROR");
	lines = count_line(fd);
	close(fd);
	if (!lines)
		error_handler("MAP ERROR");
	ft_printf("Lines %d\n", lines);
	map = (char **)ft_calloc(lines + 1, sizeof(char **));
	game->map_height =  lines;
	if (!map)
		error_handler("MALLOC ERROR");
	fd = open(name, O_RDONLY);
    if (fd < 2)
        error_handler("FILE ERROR");
	map = load_map(fd, map);
	close(fd);
	view_map(map);
	game->map_width = ft_strlen(map[0]);
	return map;
}