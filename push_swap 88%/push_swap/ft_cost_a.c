/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-gius <ldi-gius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:49:14 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/05/22 17:00:23 by ldi-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_high_num(t_stacks *stacks)
{
	t_stack	*save_a;
	int		max;
	int		i;

	i = 0;
	save_a = stacks->stack_a;
	max = stacks->stack_a->content;
	stacks->stack_b->ca = 1;
	while (stacks->stack_a != NULL)
	{
		if (stacks->stack_a->content > max)
		{
			max = stacks->stack_a->content;
			if ((i + 1) > stacks->size_a / 2)
				stacks->stack_b->ca = (i + 1) - stacks->size_a;
			else
				stacks->stack_b->ca = i + 1;
		}
		i = i + 1;
		stacks->stack_a = stacks->stack_a->next;
	}
	stacks->stack_a = save_a;
}

int	ft_save_ca(t_stacks *stacks, int i)
{
	if (i > stacks->size_a / 2)
		stacks->stack_b->ca = i - stacks->size_a;
	else
		stacks->stack_b->ca = i;
	stacks->stack_b->target = stacks->stack_a->content;
	return (1);
}

void	ft_ca_2(t_stacks *stacks)
{
	t_stack	*save_a;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	save_a = stacks->stack_a;
	while (stacks->stack_a != NULL)
	{
		if (stacks->stack_a->content > stacks->stack_b->content && flag == 0)
			flag = ft_save_ca(stacks, i);
		else if (stacks->stack_a->content > stacks->stack_b->content)
		{
			if (stacks->stack_b->target > stacks->stack_a->content)
				flag = ft_save_ca(stacks, i);
		}
		i = i + 1;
		stacks->stack_a = stacks->stack_a->next;
	}
	stacks->stack_a = save_a;
	if (flag == 0)
		ft_high_num(stacks);
}

void	ft_ca(t_stacks *stacks)
{
	t_stack	*save_b;

	save_b = stacks->stack_b;
	while (stacks->stack_b->next != NULL)
	{
		ft_ca_2(stacks);
		stacks->stack_b = stacks->stack_b->next;
	}
	ft_ca_2(stacks);
	stacks->stack_b = save_b;
}
