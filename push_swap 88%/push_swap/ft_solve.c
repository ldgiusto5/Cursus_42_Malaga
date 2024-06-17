/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-gius <ldi-gius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:09:29 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/05/22 16:58:51 by ldi-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_min_cost(t_stacks *stacks)
{
	int		min;
	t_stack	*save_b;

	save_b = stacks->stack_b;
	min = ft_abs(stacks->stack_b->ca, stacks->stack_b->cb);
	while (stacks->stack_b != NULL)
	{
		if (min > ft_abs(stacks->stack_b->ca, stacks->stack_b->cb))
			min = ft_abs(stacks->stack_b->ca, stacks->stack_b->cb);
		stacks->stack_b = stacks->stack_b->next;
	}
	stacks->stack_b = save_b;
	while (min != ft_abs(stacks->stack_b->ca, stacks->stack_b->cb))
	{
		stacks->stack_b = stacks->stack_b->next;
	}
	stacks->ca_move = stacks->stack_b->ca;
	stacks->cb_move = stacks->stack_b->cb;
	stacks->stack_b = save_b;
}

int	ft_is_a_ordered(t_stacks *stacks)
{
	t_stack	*save;
	int		flag;

	flag = 0;
	save = stacks->stack_a;
	while (stacks->stack_a->next != NULL)
	{
		if (stacks->stack_a->content > stacks->stack_a->next->content)
			flag = flag + 1;
		stacks->stack_a = stacks->stack_a->next;
	}
	if (stacks->stack_a->content > save->content)
		flag = flag + 1;
	stacks->stack_a = save;
	return (flag);
}

int	ft_ra_or_rra(t_stacks *stacks)
{
	t_stack	*save;
	int		change;

	change = 1;
	save = stacks->stack_a;
	while (stacks->stack_a->next != NULL)
	{
		if (stacks->stack_a->content > stacks->stack_a->next->content)
		{
			if (change <= stacks->size_a / 2)
			{
				stacks->stack_a = save;
				return (ft_ra(stacks, 0), 1);
			}
			else if (change > stacks->size_a / 2)
			{
				stacks->stack_a = save;
				return (ft_rra(stacks, 0), 1);
			}
		}
		change = change + 1;
		stacks->stack_a = stacks->stack_a->next;
	}
	stacks->stack_a = save;
	return (0);
}

void	ft_next_move(t_stacks *stacks)
{
	if (stacks->ca_move == 0 && stacks->cb_move == 0)
		ft_pa(stacks);
	else if (stacks->ca_move == 0 && stacks->cb_move > 0)
		ft_rb(stacks, 0);
	else if (stacks->ca_move == 0 && stacks->cb_move < 0)
		ft_rrb(stacks, 0);
	else if (stacks->ca_move > 0 && stacks->cb_move <= 0)
		ft_ra(stacks, 0);
	else if (stacks->ca_move > 0 && stacks->cb_move > 0)
		ft_rr(stacks);
	else if (stacks->ca_move < 0 && stacks->cb_move >= 0)
		ft_rra(stacks, 0);
	else if (stacks->ca_move < 0 && stacks->cb_move < 0)
		ft_rrr(stacks);
}

void	ft_solve(t_stacks *stacks)
{
	if (ft_is_a_ordered(stacks) > 1)
	{
		while (stacks->size_a > 3)
			ft_pb(stacks);
		if (ft_is_a_ordered(stacks) > 1)
			ft_sa(stacks, 0);
		while (stacks->size_b != 0)
		{
			ft_cb(stacks);
			ft_ca(stacks);
			ft_min_cost(stacks);
			ft_next_move(stacks);
		}
	}
	while (ft_ra_or_rra(stacks))
		continue ;
}

		//ft_printf("No ordenado\n");  //justo después del primer if en solve