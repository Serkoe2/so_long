/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:08:04 by cchekov           #+#    #+#             */
/*   Updated: 2021/07/17 19:19:45 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(unsigned int num)
{
	char	*str;
	int		count;

	if (num == 0)
		return (ft_putchar('0'));
	str = ft_printf_itoa(num, 10, 0);
	if (str == 0)
		return (-1);
	count = ft_putstr(str);
	free (str);
	return (count);
}
