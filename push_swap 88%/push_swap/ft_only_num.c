/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-gius <ldi-gius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:41:04 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/05/22 16:27:51 by ldi-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_only_num(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if (str[i] == '\0')
		return (1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] < 58 && str[i] > 47)
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}

int	ft_check_argv(t_stacks *stacks)
{
	int		i;
	int		j;
	char	*str;

	i = 1;
	while (stacks->newargv[i] != NULL)
	{
		if (ft_only_num(stacks->newargv[i]) == 1)
			return (ft_printf("Error\n"), 1);
		i++;
	}
	i = 1;
	while (stacks->newargv[i] != NULL)
	{
		str = stacks->newargv[i];
		j = 1;
		while (stacks->newargv[j] != NULL)
		{
			if (j != i && ft_atoi(str) == ft_atoi(stacks->newargv[j]))
				return (ft_printf("Error\n"), 1);
			j++;
		}
		i++;
	}
	return (0);
}
