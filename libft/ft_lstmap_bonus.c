/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:15:33 by cchekov           #+#    #+#             */
/*   Updated: 2021/05/15 20:01:51 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**result;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	result = (t_list **)malloc(sizeof(t_list *));
	if (!result)
		return (NULL);
	*result = NULL;
	while (lst)
	{
		temp = (t_list *)malloc(sizeof(t_list));
		if (!temp)
		{
			ft_lstclear(result, del);
			return (NULL);
		}
		temp->content = f(lst->content);
		temp->next = NULL;
		ft_lstadd_back(result, temp);
		lst = lst->next;
	}
	temp = *result;
	free(result);
	return (temp);
}
