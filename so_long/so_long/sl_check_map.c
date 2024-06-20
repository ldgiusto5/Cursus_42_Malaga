/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:08:32 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/06/20 15:43:09 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_counts(t_sl *sl)
{
	if (sl->player_num != 1)
	{
		ft_free_game(sl, "Error with player\n");
	}
	if (sl->exit_num != 1)
	{
		ft_free_game(sl, "Error with exit\n");
	}
	if (sl->chest_num < 1)
	{
		ft_free_game(sl, "Error with chests\n");
	}
}

void	ft_check_elemnts(t_sl *sl)
{
	int	i;
	int	j;

	i = 0;
	while (sl->map_splited[i])
	{
		j = 0;
		while (sl->map_splited[i][j])
		{
			if (ft_strchr("PEC01X", sl->map_splited[i][j]) == NULL)
				ft_free_game(sl, "Use only PEC01X in map, please\n");
			if (sl->map_splited[i][j] == 'P')
			{
				sl->player_num++;
				sl->player_pos_x = j;
				sl->player_pos_y = i;
			}
			if (sl->map_splited[i][j] == 'C')
				sl->chest_num++;
			if (sl->map_splited[i][j] == 'E')
				sl->exit_num++;
			j++;
		}
		i++;
	}
}

void	ft_check_map(t_sl *sl)
{
	int	i;
	int	j;

	i = 0;
	while (sl->map_splited[i])
	{
		j = 0;
		while (sl->map_splited[i][j])
			j++;
		if (j != sl->width)
			ft_free_game(sl, "Not rectangle map\n");
		i++;
	}
	ft_check_elemnts(sl);
	ft_check_counts(sl);
	ft_check_win(sl);
}
