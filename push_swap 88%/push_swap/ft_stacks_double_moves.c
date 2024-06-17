/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks_double_moves.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-gius <ldi-gius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:55:46 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/05/22 16:19:25 by ldi-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stacks *stacks)
{
	ft_sa(stacks, 1);
	ft_sb(stacks, 1);
	ft_printf("ss\n");
}

void	ft_rr(t_stacks *stacks)
{
	ft_ra(stacks, 1);
	ft_rb(stacks, 1);
	ft_printf("rr\n");
}

void	ft_rrr(t_stacks *stacks)
{
	ft_rra(stacks, 1);
	ft_rrb(stacks, 1);
	ft_printf("rrr\n");
}
