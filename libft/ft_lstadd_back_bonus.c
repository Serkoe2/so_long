/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:34:34 by cchekov           #+#    #+#             */
/*   Updated: 2021/10/30 21:35:58 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;
	if (!lst || !new)
		return ;
	//printf("lst = %p, first = %p\n", lst, *lst);
	temp = ft_lstlast(*lst);
	//printf("lst = %p, first = %p\n", lst, *lst);
	if (!temp)
		*lst = new;
	else
		temp->next = new;
}
