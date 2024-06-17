/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:37:09 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/06/17 11:44:15 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_sl
{
    mlx_t   		*mlx;
    mlx_image_t		*player;
	mlx_image_t		*backg;
	mlx_image_t		*wall;
	mlx_image_t		*exit;
	mlx_image_t		*enemy;
	mlx_image_t		*chest;
	int				player_num;
	int				player_pos_x;
	int				player_pos_y;
	int				enemy_num;
	int				chest_num;
	int				exit_num;
	char**			map_splited;
	char**			map_cpy;
	char*			map_string;
    int     		height;
    int     		width;

}   t_sl;

#endif