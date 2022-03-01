/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:01:06 by cchekov           #+#    #+#             */
/*   Updated: 2021/05/06 15:58:57 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int symbol, size_t n)
{
	char	*ptr_src;
	char	*ptr_dest;
	char	c;

	ptr_src = (char *)src;
	ptr_dest = (char *)dest;
	c = (char)symbol;
	while (n--)
	{
		*ptr_dest++ = *ptr_src;
		if (*ptr_src == c)
			return (ptr_dest);
		ptr_src++;
	}
	return (NULL);
}
