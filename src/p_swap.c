/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <abhousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:08:13 by abhousse          #+#    #+#             */
/*   Updated: 2022/11/16 06:08:14 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"

void	p_swap(t_d_list **top)
{
	int	tmp;

	if (top == NULL || is_empty(*top) || (*top)->next == NULL)
		return ;
	else
	{
		tmp = (*top)->next->content;
		(*top)->next->content = (*top)->content;
		(*top)->content = tmp;
	}
}

void	sa(t_d_list **top_a)
{
	p_swap(top_a);
}

void	sb(t_d_list **top_b)
{
	p_swap(top_b);
}

void	p_sswap(t_d_list **top_a, t_d_list **top_b)
{
	p_swap(top_a);
	p_swap(top_b);
}
