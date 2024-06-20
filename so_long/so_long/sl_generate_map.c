/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_generate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:22:53 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/06/20 15:41:39 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(mlx_t *mlx, int height, int width, t_sl *sl)
{
	mlx_image_to_window(mlx, sl->floor, width * 64, height * 64);
	mlx_image_to_window(mlx, sl->exit, width * 64, height * 64);
}

void	ft_enemy(mlx_t *mlx, int height, int width, t_sl *sl)
{
	mlx_image_to_window(mlx, sl->floor, width * 64, height * 64);
	mlx_image_to_window(mlx, sl->enemy, width * 64, height * 64);
}

void	ft_chest(mlx_t *mlx, int height, int width, t_sl *sl)
{
	mlx_image_to_window(mlx, sl->floor, width * 64, height * 64);
	mlx_image_to_window(mlx, sl->chest, width * 64, height * 64);
}

void	ft_generate_map(mlx_t *mlx, t_sl *sl)
{
	int	i;
	int	j;

	i = 0;
	while (sl->map_splited[i])
	{
		j = 0;
		while (sl->map_splited[i][j])
		{
			if (sl->map_splited[i][j] == '1')
				ft_wall(mlx, i, j, sl);
			else if (sl->map_splited[i][j] == '0')
				ft_floor(mlx, i, j, sl);
			else if (sl->map_splited[i][j] == 'C')
				ft_chest(mlx, i, j, sl);
			else if (sl->map_splited[i][j] == 'E')
				ft_exit(mlx, i, j, sl);
			else if (sl->map_splited[i][j] == 'P')
				ft_player(mlx, i, j, sl);
			else if (sl->map_splited[i][j] == 'X')
				ft_enemy(mlx, i, j, sl);
			j++;
		}
		i++;
	}
}
