/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:14:29 by cchekov           #+#    #+#             */
/*   Updated: 2021/07/17 19:20:16 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		result;
	int		count;
	va_list	args;

	va_start(args, str);
	result = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			count = ft_parse(str, args);
			if (count == -1)
				return (-1);
			result = count + result;
			str++;
		}
		else
			result = result + ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (result);
}
