/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:13:41 by cchekov           #+#    #+#             */
/*   Updated: 2021/07/17 19:18:21 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int num, char cas)
{
	char	*str;
	int		count;

	if (num == 0)
		return (ft_putchar('0'));
	if (cas == 'x')
		str = ft_printf_itoa(num, 16, 0);
	else
		str = ft_printf_itoa(num, 16, 1);
	if (str == 0)
		return (-1);
	count = ft_putstr(str);
	free (str);
	return (count);
}
