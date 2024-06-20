/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_generate_map_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:25:31 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/06/20 15:42:04 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_wall(mlx_t *mlx, int height, int width, t_sl *sl)
{
	mlx_image_to_window(mlx, sl->wall, width * 64, height * 64);
}

void	ft_floor(mlx_t *mlx, int height, int width, t_sl *sl)
{
	mlx_image_to_window(mlx, sl->floor, width * 64, height * 64);
}

void	ft_player(mlx_t *mlx, int height, int width, t_sl *sl)
{
	mlx_image_to_window(mlx, sl->floor, width * 64, height * 64);
	mlx_image_to_window(mlx, sl->player, width * 64, height * 64);
	sl->move_x = height;
	sl->move_y = width;
}
