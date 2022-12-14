/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <abhousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:08:31 by abhousse          #+#    #+#             */
/*   Updated: 2022/11/16 06:08:35 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(int *first, int *second)
{
	int	temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

int	partition(int arr[], int lower, int upper)
{
	int	i;
	int	j;
	int	pivot;

	i = (lower - 1);
	pivot = arr[upper];
	j = lower;
	while (j < upper)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[upper]);
	return (i + 1);
}

void	quicksort(int arr[], int lower, int upper)
{
	int	partitionindex;

	if (upper > lower)
	{
		partitionindex = partition(arr, lower, upper);
		quicksort(arr, lower, partitionindex - 1);
		quicksort(arr, partitionindex + 1, upper);
	}
}

int	*content_of_next(t_stk *top)
{
	int			i;
	t_d_list	*tmp;
	int			*array;

	array = malloc(sizeof(int) * top->len_a);
	if (array == NULL)
		return (NULL);
	i = 0;
	tmp = top->stk_a;
	while (tmp)
	{
		array[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	quicksort(array, 0, top->len_a - 1);
	return (array);
}
