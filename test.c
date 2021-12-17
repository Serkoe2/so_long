/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:50:03 by cchekov           #+#    #+#             */
/*   Updated: 2021/11/02 00:03:34 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "gnl/get_next_line.h"
#include "libft/libft.h"

int main()
{
    int  fd;
    char *name = "maps/Coral-Sun.ber";
    char *line;
    
    fd = open(name, O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        printf("%s\n", line);
        free(line);
        line = get_next_line(fd);
    }
}