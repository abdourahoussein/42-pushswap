/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <abhousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:07:43 by abhousse          #+#    #+#             */
/*   Updated: 2022/11/16 06:07:44 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/push_swap.h"

int	check_error(char *str)
{
	int	value;

	value = 0;
	if (is_plus_or_minus(*str) && !ft_isdigit(*(str + 1)))
		return (1);
	if (is_plus_or_minus(*str) && str++)
		value = 0;
	while (*str)
	{
		while (is_space(*str))
			str++;
		if (!ft_isdigit(*str))
			value = 1;
		str++;
	}
	return (value);
}

int	check_error_overflow(char *str)
{
	long	num;

	num = ft_atoi_long(str);
	if (num > MAX_INT || num < MIN_INT)
		return (1);
	return (0);
}

void	check_dupl_args(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (!ft_strcmp(str[i], str[j]))
			{
				free_tab_without_index(str);
				ft_print_error();
			}
			j++;
		}
		i++;
	}
}

void	ft_print_error(void)
{
	ft_printf("Error\n");
	exit(1);
}
