/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 07:19:07 by cchekov           #+#    #+#             */
/*   Updated: 2021/05/15 21:18:26 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *src)
{
	int	result;
	int	sign;

	result = 0;
	if (ft_strlen(src) == 0)
		return (0);
	while (ft_strchr("\n\t\v\f\r ", *src))
		src++;
	if (*src == '\0')
		return (0);
	if (*src == '-')
		sign = -1;
	else
		sign = 1;
	if (*src == '+' || *src == '-')
		src++;
	while (*src)
	{
		if (ft_isdigit(*src) == 0)
			break ;
		result = result * 10 + *src - '0';
		src++;
	}
	return (result * sign);
}
