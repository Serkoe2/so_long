/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 23:24:02 by cchekov           #+#    #+#             */
/*   Updated: 2021/05/13 20:51:25 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	symb;
	unsigned char	*ptr_src;

	ptr_src = (unsigned char *)s;
	symb = c;
	while (n--)
	{
		if (*ptr_src == symb)
			return ((void *)ptr_src);
		ptr_src++;
	}
	return (NULL);
}
