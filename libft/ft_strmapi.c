/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:04:20 by cchekov           #+#    #+#             */
/*   Updated: 2021/05/13 21:53:34 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*result;
	unsigned int		counter;

	if (!s)
		return (NULL);
	result = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!result)
		return (NULL);
	counter = 0;
	while (s[counter])
	{
		result[counter] = f(counter, s[counter]);
		counter++;
	}
	result[counter] = '\0';
	return (result);
}
