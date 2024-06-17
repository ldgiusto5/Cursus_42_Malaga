/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost_b_and_abs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-gius <ldi-gius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:52:55 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/05/22 16:59:38 by ldi-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int a, int b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	return (a + b);
}

void	ft_cb(t_stacks *stacks)
{
	t_stack	*save;
	int		i;

	i = 0;
	save = stacks->stack_b;
	while (stacks->stack_b != NULL)
	{
		if (i <= stacks->size_b / 2)
			stacks->stack_b->cb = i;
		else
			stacks->stack_b->cb = (i - stacks->size_b);
		stacks->stack_b = stacks->stack_b->next;
		i = i + 1;
	}
	stacks->stack_b = save;
}
