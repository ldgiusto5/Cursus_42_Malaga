/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:28:31 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/06/19 10:20:08 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_ini(t_sl *sl)
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
			return;
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
	while(sl->map_splited[i])
	{
		j = 0;
		while (sl->map_splited[i][j])
		{
			if (ft_strchr("PEC01X", sl->map_splited[i][j]) == NULL)
			{
				ft_free_game(sl, "Use only PEC01X in map, please\n");
			}
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

char    *ft_read_file(const char *file, t_sl *sl)
{
    int		fd;
	int		fsize;
	char	*buff;
	char	*file_read;

	fsize = 0;
	buff = malloc(sizeof(char) * 2);
	fd = open(file, O_RDONLY);
	while (read(fd, buff, 1) == 1)
		fsize++;
	free(buff);
	close(fd);
	if (fsize == 0)
		ft_free_game(sl, "Empty file/folder\n");
	fd = open(file, O_RDONLY);
	file_read = malloc(sizeof(char) * fsize + 1);
	read(fd, file_read, fsize);
	file_read[fsize] = '\0';
	close(fd);
	return (file_read);
}

void   ft_read_map(const char *file, t_sl *sl)
{
    int i;
    int j;

    i = 0;
    sl->map_string = ft_read_file(file, sl);
    sl->map_splited = ft_split(sl->map_string, '\n');
	sl->map_cpy= ft_split(sl->map_string, '\n');
	while (sl->map_splited[i])
	{
		j = 0;
		while (sl->map_splited[i][j])
			j++;
		i++;
	}
    sl->height = i;
    sl->width = j;
    
}

int	ft_check_ber(const char *file)
{
    int size;
    size = ft_strlen(file);
	if (size > 4)
	{
		if (file[size - 1] == 'r' && file[size - 2] == 'e' 
			&& file[size - 3] == 'b' && file[size - 4] == '.')
			return (1);
	}
    return (0);
}

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

void	ft_exit_game(t_sl *sl)
{
	ft_printf("\nTerminas con %d movimientos.\n", sl->steps);
	ft_free_game(sl, "YOU WIN\n");
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
			ft_exit_game(sl);
		else
		{
			sl->map_splited[sl->move_x - 1]
			[sl->move_y] = 'P';
			ft_generate_map(sl->mlx, sl);
			sl->steps++;
			ft_printf("\nMoves: %d", sl->steps);
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
			ft_exit_game(sl);
		else
		{
			sl->map_splited[sl->move_x + 1]
			[sl->move_y] = 'P';
			ft_generate_map(sl->mlx, sl);
			sl->steps++;
			ft_printf("\nMoves: %d", sl->steps);
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
			ft_exit_game(sl);
		else
		{
			sl->map_splited[sl->move_x]
			[sl->move_y - 1] = 'P';
			ft_generate_map(sl->mlx, sl);
			sl->steps++;
			ft_printf("\nMoves: %d", sl->steps);
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
			||	sl->map_splited[sl->move_x]
			[sl->move_y + 1] == 'X')
			ft_exit_game(sl);
		else
		{
			sl->map_splited[sl->move_x]
			[sl->move_y + 1] = 'P';
			ft_generate_map(sl->mlx, sl);
			sl->steps++;
			ft_printf("\nMoves: %d", sl->steps);
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
		{
			ft_free_game(cpy, "ESC\n");
		}
	ft_steps(cpy);
}

void	ft_run_game(t_sl *sl)
{
	mlx_key_hook(sl->mlx, ft_movement, sl);
	mlx_loop(sl->mlx);
	ft_free_game(sl, "Window closed\n");
}


int main (int argc, char **argv)
{
    t_sl    *sl;
    sl = malloc(sizeof(t_sl));
    if (argc != 2)
	{
		free(sl);
        return (ft_printf("Argument error"), 1);
	}
    ft_ini(sl);
    if (ft_check_ber(argv[1]) == 1)
    {
        ft_read_map(argv[1], sl);
		ft_check_map(sl);
		sl->mlx = mlx_init(sl->width * 64, sl->height * 64, "so_long", false);
		ft_load_textures(sl);
		ft_run_game(sl);
	}
	free(sl);
    return (0);

    /*
    mlx_t *sl;
    sl = mlx_init(128,128,"hola", false);
    return (perror("asgaefgafr"), 0);
    */
}