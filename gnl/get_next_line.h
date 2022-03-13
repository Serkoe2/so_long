/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 23:11:00 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/11 21:31:35 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

char	*get_next_line(int fd);
char	*work_with_iter(char **line, char **iter);
char	*work_with_file(int fd, char *line, char **iter);
char	*if_space_found(char *buffer, char *find, char **iter, char *line);

#endif
