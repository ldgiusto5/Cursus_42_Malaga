/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_b_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-gius <ldi-gius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:39:02 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/05/22 16:35:16 by ldi-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_stacks *stacks, int flag)
{
	t_stack	*save;

	save = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	save->next = stacks->stack_b->next;
	stacks->stack_b->next = save;
	if (flag == 0)
		ft_printf("sb\n");
}

void	ft_pb(t_stacks *stacks)
{
	t_stack	*save;

	if (stacks->stack_b == NULL)
	{
		stacks->stack_b = stacks->stack_a;
		stacks->stack_a = stacks->stack_a->next;
		stacks->stack_b->next = NULL;
	}
	else
	{
		save = stacks->stack_b;
		stacks->stack_b = stacks->stack_a;
		stacks->stack_a = stacks->stack_a->next;
		stacks->stack_b->next = save;
	}
	stacks->size_a = stacks->size_a - 1;
	stacks->size_b = stacks->size_b + 1;
	ft_printf("pb\n");
}

void	ft_rb(t_stacks *stacks, int flag)
{
	t_stack	*save;
	t_stack	*head;

	save = stacks->stack_b;
	head = stacks->stack_b->next;
	while (stacks->stack_b->next != NULL)
	{
		stacks->stack_b = stacks->stack_b->next;
	}
	stacks->stack_b->next = save;
	stacks->stack_b->next->next = NULL;
	stacks->stack_b = head;
	if (flag == 0)
		ft_printf("rb\n");
}

void	ft_rrb(t_stacks *stacks, int flag)
{
	t_stack	*save;
	t_stack	*head;

	save = stacks->stack_b;
	while (stacks->stack_b->next->next != NULL)
	{
		stacks->stack_b = stacks->stack_b->next;
	}
	stacks->stack_b->next->next = save;
	head = stacks->stack_b->next;
	stacks->stack_b->next = NULL;
	stacks->stack_b = head;
	if (flag == 0)
		ft_printf("rrb\n");
}
