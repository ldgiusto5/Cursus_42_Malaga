/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:32:13 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/06/20 15:39:32 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_chest_win(t_sl *sl)
{
	int	i;
	int	j;

	i = 0;
	while (sl->map_cpy[i])
	{
		j = 0;
		while (sl->map_cpy[i][j])
		{
			if (sl->map_cpy[i][j] == 'C')
				ft_free_game(sl, "Can't take all chests\n");
			if (sl->map_cpy[i][j] == 'E')
				ft_free_game(sl, "Can't find the exit\n");
			j++;
		}
		i++;
	}
}

void	ft_flood_fill(t_sl *sl, int pl_pos_x, int pl_pos_y)
{
	char	pos;

	pos = sl->map_cpy[pl_pos_y][pl_pos_x];
	if (pos != '1' && pos != 'F' && pos != 'X' && pos != 'J')
	{
		if (sl->map_cpy[pl_pos_y][pl_pos_x] == 'E')
		{
			sl->map_cpy[pl_pos_y][pl_pos_x] = 'J';
			return ;
		}
		sl->map_cpy[pl_pos_y][pl_pos_x] = 'F';
		ft_flood_fill(sl, pl_pos_x + 1, pl_pos_y);
		ft_flood_fill(sl, pl_pos_x - 1, pl_pos_y);
		ft_flood_fill(sl, pl_pos_x, pl_pos_y + 1);
		ft_flood_fill(sl, pl_pos_x, pl_pos_y - 1);
	}
}

void	ft_check_win(t_sl *sl)
{
	int	pl_pos_x;
	int	pl_pos_y;

	pl_pos_x = sl->player_pos_x;
	pl_pos_y = sl->player_pos_y;
	ft_flood_fill(sl, pl_pos_x, pl_pos_y);
	ft_check_chest_win(sl);
}
