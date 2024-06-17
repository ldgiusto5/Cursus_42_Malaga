/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-gius <ldi-gius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:01:26 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/05/22 17:00:00 by ldi-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				ca;
	int				cb;
	int				target;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacks
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	char			**newargv;
	int				n;
	int				size_a;
	int				size_b;
	int				i;
	int				ca_move;
	int				cb_move;
}					t_stacks;

void	ft_stackaddlast(t_stack *new, t_stacks *stacks);
void	ft_ini_stack(t_stacks *stacks);
int		ft_check_argv(t_stacks *stacks);
int		ft_split_add_to_newargv(char **argv, char c, t_stacks *stacks);
void	ft_sb(t_stacks *stacks, int flag);
void	ft_sa(t_stacks *stacks, int flag);
void	ft_ss(t_stacks *stacks);
void	ft_ra(t_stacks *stacks, int flag);
void	ft_rb(t_stacks *stacks, int flag);
void	ft_rr(t_stacks *stacks);
void	ft_rra(t_stacks *stacks, int flag);
void	ft_rrb(t_stacks *stacks, int flag);
void	ft_rrr(t_stacks *stacks);
void	ft_pb(t_stacks *stacks);
void	ft_pa(t_stacks *stacks);
void	ft_solve(t_stacks *stacks);
void	ft_ca(t_stacks *stacks);
void	ft_cb(t_stacks *stacks);
int		ft_abs(int a, int b);
int		ft_printf(char const *str, ...);

#endif