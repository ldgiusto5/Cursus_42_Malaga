/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-gius <ldi-gius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:42:07 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/06/21 10:42:09 by ldi-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

void	ft_free_mlx(void *param)
{
	t_sl	*delete;

	delete = (t_sl *)param;
	if (delete->floor != 0)
		mlx_delete_image(delete->mlx, delete->floor);
	if (delete->wall != 0)
		mlx_delete_image(delete->mlx, delete->wall);
	if (delete->chest != 0)
		mlx_delete_image(delete->mlx, delete->chest);
	if (delete->player != 0)
		mlx_delete_image(delete->mlx, delete->player);
	if (delete->exit != 0)
		mlx_delete_image(delete->mlx, delete->exit);
	if (delete->enemy != 0)
		mlx_delete_image(delete->mlx, delete->enemy);
	if (delete->phrase != 0)
		mlx_delete_image(delete->mlx, delete->phrase);
	if (delete->steps_img != 0)
		mlx_delete_image(delete->mlx, delete->steps_img);
	if (delete->mlx != 0)
		mlx_terminate(delete->mlx);
}

void	ft_free_game(void *param, char *str)
{
	t_sl	*delete;

	delete = (t_sl *)param;
	ft_free_mlx(param);
	free(delete->map_string);
	if (delete->map_splited != 0)
		ft_free_map(delete->map_splited);
	if (delete->map_cpy != 0)
		ft_free_map(delete->map_cpy);
	free(delete);
	ft_printf("%s", str);
	exit(EXIT_SUCCESS);
}
