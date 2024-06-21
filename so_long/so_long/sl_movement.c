/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-gius <ldi-gius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:41:44 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/06/21 10:41:46 by ldi-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_sl *sl)
{
	if (sl->map_splited[sl->move_x - 1]
		[sl->move_y] != '1'
		&& (sl->map_splited[sl->move_x - 1]
			[sl->move_y] != 'E'
			|| sl->chest_num == 0))
	{
		sl->map_splited[sl->move_x][sl->move_y] = '0';
		if (sl->map_splited[sl->move_x - 1]
			[sl->move_y] == 'C')
			sl->chest_num--;
		if ((sl->map_splited[sl->move_x - 1]
				[sl->move_y] == 'E' && sl->chest_num == 0)
			|| sl->map_splited[sl->move_x - 1]
			[sl->move_y] == 'X')
			ft_free_game(sl, "Finish\n");
		else
		{
			sl->map_splited[sl->move_x - 1]
			[sl->move_y] = 'P';
			ft_generate_map(sl->mlx, sl);
			sl->steps++;
			ft_printf("Moves: %d \n", sl->steps);
		}
	}
}

void	ft_move_down(t_sl *sl)
{
	if (sl->map_splited[sl->move_x + 1]
		[sl->move_y] != '1'
		&& (sl->map_splited[sl->move_x + 1]
			[sl->move_y] != 'E'
			|| sl->chest_num == 0))
	{
		sl->map_splited[sl->move_x][sl->move_y] = '0';
		if (sl->map_splited[sl->move_x + 1]
			[sl->move_y] == 'C')
			sl->chest_num--;
		if ((sl->map_splited[sl->move_x + 1]
				[sl->move_y] == 'E' && sl->chest_num == 0)
			|| sl->map_splited[sl->move_x + 1]
			[sl->move_y] == 'X')
			ft_free_game(sl, "Finish\n");
		else
		{
			sl->map_splited[sl->move_x + 1]
			[sl->move_y] = 'P';
			ft_generate_map(sl->mlx, sl);
			sl->steps++;
			ft_printf("Moves: %d \n", sl->steps);
		}
	}
}

void	ft_move_left(t_sl *sl)
{
	if (sl->map_splited[sl->move_x]
		[sl->move_y - 1] != '1'
		&& (sl->map_splited[sl->move_x]
			[sl->move_y - 1] != 'E'
			|| sl->chest_num == 0))
	{
		sl->map_splited[sl->move_x][sl->move_y] = '0';
		if (sl->map_splited[sl->move_x]
			[sl->move_y - 1] == 'C')
			sl->chest_num--;
		if ((sl->map_splited[sl->move_x]
				[sl->move_y - 1] == 'E' && sl->chest_num == 0)
			|| sl->map_splited[sl->move_x]
			[sl->move_y - 1] == 'X')
			ft_free_game(sl, "Finish\n");
		else
		{
			sl->map_splited[sl->move_x]
			[sl->move_y - 1] = 'P';
			ft_generate_map(sl->mlx, sl);
			sl->steps++;
			ft_printf("Moves: %d \n", sl->steps);
		}
	}
}

void	ft_move_right(t_sl *sl)
{
	if (sl->map_splited[sl->move_x]
		[sl->move_y + 1] != '1'
		&& (sl->map_splited[sl->move_x]
			[sl->move_y + 1] != 'E'
			|| sl->chest_num == 0))
	{
		sl->map_splited[sl->move_x][sl->move_y] = '0';
		if (sl->map_splited[sl->move_x]
			[sl->move_y + 1] == 'C')
			sl->chest_num--;
		if ((sl->map_splited[sl->move_x]
				[sl->move_y + 1] == 'E' && sl->chest_num == 0)
			|| sl->map_splited[sl->move_x]
			[sl->move_y + 1] == 'X')
			ft_free_game(sl, "Finish\n");
		else
		{
			sl->map_splited[sl->move_x]
			[sl->move_y + 1] = 'P';
			ft_generate_map(sl->mlx, sl);
			sl->steps++;
			ft_printf("Moves: %d \n", sl->steps);
		}
	}
}

void	ft_movement(mlx_key_data_t paramkey, void *param)
{
	t_sl	*cpy;

	cpy = (t_sl *)param;
	if ((paramkey.key == MLX_KEY_W || paramkey.key == MLX_KEY_UP)
		&& paramkey.action == MLX_PRESS)
		ft_move_up(cpy);
	if ((paramkey.key == MLX_KEY_S || paramkey.key == MLX_KEY_DOWN)
		&& paramkey.action == MLX_PRESS)
		ft_move_down(cpy);
	if ((paramkey.key == MLX_KEY_A || paramkey.key == MLX_KEY_LEFT)
		&& paramkey.action == MLX_PRESS)
		ft_move_left(cpy);
	if ((paramkey.key == MLX_KEY_D || paramkey.key == MLX_KEY_RIGHT)
		&& paramkey.action == MLX_PRESS)
		ft_move_right(cpy);
	if ((paramkey.key == MLX_KEY_ESCAPE || paramkey.key == MLX_KEY_Q)
		&& paramkey.action == MLX_PRESS)
		ft_free_game(cpy, "ESC\n");
	ft_steps(cpy);
}
