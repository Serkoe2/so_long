/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 23:08:23 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/09 23:37:47 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 30

void	clean(char **target)
{
	free(*target);
	*target = NULL;
}

char	*work_with_iter(char **line, char **iter)
{
	char			*find;
	unsigned int	count;

	find = ft_strchr(*iter, '\n');
	if (!find)
	{
		*line = ft_strjoin(*iter, "\0");
		clean(iter);
	}
	else
	{
		count = find - *iter;
		*line = ft_substr(*iter, 0, count);
		ft_strlcpy(*iter, *iter + count + 1, ft_strlen(*iter));
	}
	return (find);
}

char	*if_space_found(char *buffer, char *find, char **iter, char *line)
{
	char	*temp;

	temp = NULL;
	buffer[find - buffer] = '\0';
	if (line)
	{
		temp = ft_strjoin(line, buffer);
		clean(&line);
		line = temp;
	}
	else
		line = ft_strjoin(line, buffer);
	if (*iter)
		clean(iter);
	*iter = ft_strjoin(find + 1, "\0");
	if (!(*iter))
	{
		clean(&line);
		return (line);
	}
	// temp = ft_strjoin(line, "\n");
	// free(line);
	return (line);
}

char	*work_with_file(int fd, char *line, char **iter)
{
	int		count;
	char	buffer[BUFFER_SIZE + 1];
	char	*find;
	char	*temp;

	count = read(fd, &buffer, BUFFER_SIZE);
	while (count > 0)
	{
		buffer[count] = '\0';
		find = ft_strchr(buffer, '\n');
		if (find)
		{
			line = if_space_found(buffer, find, iter, line);
			return (line);
		}
		temp = ft_strjoin(line, buffer);
		if (line)
			clean(&line);
		line = temp;
		count = read(fd, &buffer, BUFFER_SIZE);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char			*iter = NULL;
	char				*line;
	char				*result;

	line = NULL;
	result = NULL;
	if ((read(fd, line, 0)) != 0)
		return (result);
	if (iter && *iter)
	{
		if (work_with_iter(&line, &iter))
		{
			// result = ft_strjoin(line, "\n");
			// free(line);
			return (line);
		}
	}
	line = work_with_file(fd, line, &iter);
	return (line);
}
