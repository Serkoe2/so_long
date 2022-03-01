/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:46:55 by cchekov           #+#    #+#             */
/*   Updated: 2021/07/17 19:31:11 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long long p)
{
	char	*str;
	int		count;

	if (!p)
		return (ft_putstr("0x0"));
	str = ft_printf_itoa(p, 16, 0);
	if (!str)
		return (-1);
	count = ft_putstr("0x");
	count = count + ft_putstr(str);
	free (str);
	return (count);
}
