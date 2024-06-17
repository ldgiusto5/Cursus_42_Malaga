/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-gius <ldi-gius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:50:31 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/03/29 20:43:31 by ldi-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackaddlast(t_stack *new, t_stacks *stacks)
{
	t_stack	*save;

	save = stacks->stack_a;
	if (save == NULL)
	{
		stacks->stack_a = new;
		return ;
	}
	while (stacks->stack_a->next != NULL)
	{
		stacks->stack_a = stacks->stack_a->next;
	}
	stacks->stack_a->next = new;
	stacks->stack_a = save;
}

t_stack	*ft_lstnewstack(char *content)
{
	t_stack	*newstack;

	newstack = (t_stack *)malloc(sizeof(struct s_stack));
	if (!newstack)
		return (0);
	newstack -> content = ft_atoi(content);
	newstack -> next = NULL;
	return (newstack);
}

void	ft_ini_stack(t_stacks *stacks)
{
	int	i;

	i = 1;
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	while (stacks->newargv[i] != NULL)
	{
		ft_stackaddlast(ft_lstnewstack(stacks->newargv[i]), stacks);
		i++;
	}
	stacks->size_a = stacks->n - 1;
	stacks->size_b = 0;
}
