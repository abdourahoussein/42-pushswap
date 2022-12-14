/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <abhousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:08:17 by abhousse          #+#    #+#             */
/*   Updated: 2022/11/16 06:08:18 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"

int	is_plus_or_minus(int c)
{
	if (c == '+' || c == '-')
		return (!0);
	return (0);
}

int	is_space(int c)
{
	if (c == ' ' || c == '\t' || c == 32)
		return (!0);
	return (0);
}

char	*ft_strjoin_char(char *s1, char const *s2, char c)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	newstr = (char *)malloc((sizeof(char)
				* (ft_strlen(s1) + ft_strlen(s2) + 2)));
	if (newstr == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		newstr[i] = s1[i];
	free(s1);
	newstr[i++] = c;
	j = 0;
	while (s2[j] != '\0')
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	return (newstr);
}

char	**join_args(char **str)
{
	char	*ptr;
	char	**ptr2;
	int		i;

	ptr = NULL;
	i = 0;
	while (str[i] != NULL)
	{
		if (str[i][0] == '\0')
		{
			free(ptr);
			ft_print_error();
		}
		ptr = ft_strjoin_char(ptr, str[i++], ' ');
		if (ptr == NULL)
			return (NULL);
	}
	ptr2 = ft_split(ptr, ' ');
	if (ptr2 == NULL)
	{
		free(ptr);
		return (NULL);
	}
	free(ptr);
	return (ptr2);
}

long long	ft_atoi_long(const char *str)
{
	int				i;
	int				s;
	unsigned long	r;
	char			*ptr;

	ptr = (char *)str;
	i = 0;
	s = 1;
	r = 0;
	while ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == 32)
		i++;
	while ((ptr[i] == '-') || (str[i] == '+'))
	{
		if (ptr[i] == '-')
			s = s * -1;
		if (ptr[i + 1] == '-' || ptr[i + 1] == '+')
			return (0);
		i++;
	}
	while ((ptr[i] >= '0') && (ptr[i] <= '9'))
	{
		r = (r * 10) + (ptr[i] - '0');
		i++;
	}
	return (r * s);
}
