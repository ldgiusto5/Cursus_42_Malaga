/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-gius <ldi-gius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:00:04 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/05/22 16:19:07 by ldi-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	struct s_stacks	stacks;

	if (argc == 1)
		return (1);
	if (ft_split_add_to_newargv(argv, ' ', &stacks) == 1)
		return (1);
	if (ft_check_argv(&stacks) == 1)
		return (1);
	ft_ini_stack(&stacks);
	ft_solve(&stacks);
}

/*
	//put after ft_solve for check
	ft_printf("STACK A\n");
	while (stacks.stack_a->next != NULL)
	{
		ft_printf("%d\n", stacks.stack_a->content);
		stacks.stack_a = stacks.stack_a->next;
	}
	ft_printf("%d\n\nSTACK B\n", stacks.stack_a->content);
	if (stacks.stack_b != NULL)
	{
		while (stacks.stack_b->next != NULL)
		{
			ft_printf("%d  ", stacks.stack_b->content);
			ft_printf("%d  ", stacks.stack_b->cb);
			ft_printf("%d\n", stacks.stack_b->ca);
			stacks.stack_b = stacks.stack_b->next;
		}
		ft_printf("%d  ", stacks.stack_b->content);
		ft_printf("%d  ", stacks.stack_b->cb);
		ft_printf("%d\n", stacks.stack_b->ca);
	}
*/