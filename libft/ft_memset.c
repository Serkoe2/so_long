/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:50:53 by cchekov           #+#    #+#             */
/*   Updated: 2021/05/01 01:30:37 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int val, size_t n)
{
	char	c;
	char	*ptr;

	ptr = (char *)dest;
	c = (char)val;
	while (n--)
		*ptr++ = c;
	return (dest);
}
