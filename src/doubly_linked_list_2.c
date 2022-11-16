/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <abhousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:07:35 by abhousse          #+#    #+#             */
/*   Updated: 2022/11/16 06:07:36 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"

void	ft_d_lstdelone(t_d_list *lst, void (*del) (void *))
{
	if (!lst || del == NULL)
		return ;
	free(lst);
}

void	ft_d_lstclear(t_d_list **lst, void (*del)(void *))
{
	t_d_list	*tmp;

	if (del == NULL || lst == NULL)
		return ;
	while (*lst != NULL)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_d_lstdelone(tmp, del);
	}
}
