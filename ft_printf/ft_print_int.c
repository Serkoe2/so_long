/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:49:12 by cchekov           #+#    #+#             */
/*   Updated: 2021/07/17 19:19:00 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int num)
{
	char			*str;
	int				count;
	char			sign;
	unsigned int	temp;

	sign = '\0';
	temp = num;
	count = 0;
	if (num == 0)
		return (ft_putstr("0"));
	if (num < 0)
	{
		sign = '-';
		temp = num * -1;
	}
	str = ft_printf_itoa(temp, 10, 0);
	if (!str)
		return (-1);
	if (sign)
		count = ft_putchar(sign);
	count = count + ft_putstr(str);
	free (str);
	return (count);
}
