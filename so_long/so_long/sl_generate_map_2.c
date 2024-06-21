/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_generate_map_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-gius <ldi-gius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:42:01 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/06/21 10:42:03 by ldi-gius         ###   ########.fr       */
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
