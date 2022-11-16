/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <abhousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:07:31 by abhousse          #+#    #+#             */
/*   Updated: 2022/11/16 06:07:32 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/push_swap.h"

void	display_actions(void (*action)(), char *operation_str, t_stk *top)
{
	if (action == &ra || action == &rra || action == &sa)
		action(&top->stk_a);
	else if (action == &rb || action == &rrb || action == &sb)
		action(&top->stk_b);
	else if (action == &p_rrotate || action == &p_rrev_rotate
		|| action == &p_sswap || action == &pa || action == &pb)
		action(&top->stk_a, &top->stk_b);
	ft_printf("%s", operation_str);
}
