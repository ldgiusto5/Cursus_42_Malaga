/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:28:31 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/06/20 16:18:09 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_steps(t_sl *sl)
{
	char				*str;

	str = ft_itoa(sl->steps);
	if (sl->steps < 2147483647)
	{
		sl->phrase = mlx_put_string(sl->mlx, "steps: ", 0, 0);
		mlx_image_to_window(sl->mlx, sl->phrase, 0, 0);
		sl->steps_img = mlx_put_string(sl->mlx, str, 64, 0);
		mlx_image_to_window(sl->mlx, sl->steps_img, 64, 0);
	}
	free(str);
}

void	ft_run_game(t_sl *sl)
{
	mlx_key_hook(sl->mlx, ft_movement, sl);
	mlx_loop(sl->mlx);
	ft_free_game(sl, "Window closed\n");
}

int	main(int argc, char **argv)
{
	t_sl	*sl;

	sl = malloc(sizeof(t_sl));
	if (argc != 2)
	{
		free(sl);
		return (ft_printf("Argument error"), 1);
	}
	ft_ini(sl);
	if (ft_check_ber(argv[1]) != 1)
	{
		free(sl);
		return (ft_printf("Not .ber file\n"), 1);
	}
	ft_read_map(argv[1], sl);
	ft_check_map(sl);
	sl->mlx = mlx_init(sl->width * 64, sl->height * 64, "so_long", false);
	ft_load_textures(sl);
	ft_run_game(sl);
	return (0);
}
