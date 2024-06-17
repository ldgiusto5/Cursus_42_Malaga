/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_a_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-gius <ldi-gius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:45:48 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/05/22 16:19:43 by ldi-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stacks *stacks, int flag)
{
	t_stack	*save;

	save = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	save->next = stacks->stack_a->next;
	stacks->stack_a->next = save;
	if (flag == 0)
		ft_printf("sa\n");
}

void	ft_pa(t_stacks *stacks)
{
	t_stack	*save;

	save = stacks->stack_a;
	stacks->stack_a = stacks->stack_b;
	if (stacks->stack_b->next != NULL)
		stacks->stack_b = stacks->stack_b->next;
	else
		stacks->stack_b = NULL;
	stacks->stack_a->next = save;
	stacks->size_a = stacks->size_a + 1;
	stacks->size_b = stacks->size_b - 1;
	ft_printf("pa\n");
}

void	ft_ra(t_stacks *stacks, int flag)
{
	t_stack	*save;
	t_stack	*head;

	save = stacks->stack_a;
	head = stacks->stack_a->next;
	while (stacks->stack_a->next != NULL)
	{
		stacks->stack_a = stacks->stack_a->next;
	}
	stacks->stack_a->next = save;
	stacks->stack_a->next->next = NULL;
	stacks->stack_a = head;
	if (flag == 0)
		ft_printf("ra\n");
}

void	ft_rra(t_stacks *stacks, int flag)
{
	t_stack	*save;
	t_stack	*head;

	save = stacks->stack_a;
	while (stacks->stack_a->next->next != NULL)
	{
		stacks->stack_a = stacks->stack_a->next;
	}
	stacks->stack_a->next->next = save;
	head = stacks->stack_a->next;
	stacks->stack_a->next = NULL;
	stacks->stack_a = head;
	if (flag == 0)
		ft_printf("rra\n");
}
