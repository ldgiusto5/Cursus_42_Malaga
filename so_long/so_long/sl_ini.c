/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_ini.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-gius <ldi-gius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:41:50 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/06/21 10:41:52 by ldi-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ini(t_sl *sl)
{
	sl->mlx = 0;
	sl->player = 0;
	sl->floor = 0;
	sl->wall = 0;
	sl->exit = 0;
	sl->enemy = 0;
	sl->chest = 0;
	sl->map_splited = 0;
	sl->map_cpy = 0;
	sl->map_string = 0;
	sl->height = 0;
	sl->width = 0;
	sl->player_num = 0;
	sl->enemy_num = 0;
	sl->chest_num = 0;
	sl->exit_num = 0;
	sl->move_x = 0;
	sl->move_y = 0;
	sl->steps = 0;
	sl->steps_img = 0;
	sl->phrase = 0;
}

void	ft_load_textures(t_sl *sl)
{
	mlx_texture_t	*img;

	img = mlx_load_png("./textures/player.png");
	sl->player = mlx_texture_to_image(sl->mlx, img);
	mlx_delete_texture(img);
	img = mlx_load_png("./textures/enemy.png");
	sl->enemy = mlx_texture_to_image(sl->mlx, img);
	mlx_delete_texture(img);
	img = mlx_load_png("./textures/chest.png");
	sl->chest = mlx_texture_to_image(sl->mlx, img);
	mlx_delete_texture(img);
	img = mlx_load_png("./textures/floor.png");
	sl->floor = mlx_texture_to_image(sl->mlx, img);
	mlx_delete_texture(img);
	img = mlx_load_png("./textures/exit.png");
	sl->exit = mlx_texture_to_image(sl->mlx, img);
	mlx_delete_texture(img);
	img = mlx_load_png("./textures/wall.png");
	sl->wall = mlx_texture_to_image(sl->mlx, img);
	mlx_delete_texture(img);
	ft_generate_map(sl->mlx, sl);
}
