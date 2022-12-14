/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <abhousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:09:13 by abhousse          #+#    #+#             */
/*   Updated: 2022/11/16 06:09:15 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "include/push_swap.h"

static int	check_sorted(t_stk *top, char **av)
{
	if (ft_create_stack(top, av) == -1)
		return (-1);
	if (is_sorted(top->stk_a))
	{
		free_tab_without_index(top->spl);
		ft_d_lstclear(&top->stk_a, &free);
		return (1);
	}
	return (0);
}

static void	sorting(t_stk *top)
{
	if (top->len_a == 2)
	{
		if (top->stk_a->content > top->stk_a->next->content)
			display_actions(sa, "sa\n", top);
	}
	else if (top->len_a == 3)
		sorting_three_numbers(top);
	else if (top->len_a == 4)
		sorting_four_numbers(top);
	else if (top->len_a == 5)
		sorting_five_numbers(top);
	else
	{
		main_sorting(top, 0);
		main_sorting(top, 1);
	}
}

int	main(int ac, char **av)
{
	t_stk	top;
	int		is_sorted;

	if (ac > 1)
	{
		is_sorted = check_sorted(&top, av);
		if (is_sorted == -1)
			return (-1);
		else if (is_sorted == 1)
			return (0);
		top.sorted_array = content_of_next(&top);
		if (top.sorted_array == NULL)
		{
			free_tab_without_index(top.spl);
			ft_d_lstclear(&top.stk_a, &free);
			return (-1);
		}
		sorting(&top);
		free_tab_without_index(top.spl);
		ft_d_lstclear(&top.stk_a, &free);
		free(top.sorted_array);
	}
	return (0);
}
