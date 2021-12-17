/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 23:11:00 by cchekov           #+#    #+#             */
/*   Updated: 2021/11/01 12:03:01 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 30
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

char	    *get_next_line(int fd);
char		*ft_strjoin(char const *s1, char const *s2);
char		*work_with_iter(char **line, char *iter);
char		*work_with_file(int fd, char *line, char **iter);
size_t	    ft_strlcpy_gnl(char *dest, char *src);

#endif