/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:28:31 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/06/18 12:14:06 by jjaen-mo         ###   ########.fr       */
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
				perror("Can't take all chests");	//NEED EXIT
			if (sl->map_cpy[i][j] == 'E')
				perror("Can't find the exit");	//NEED EXIT
			j++;
		}
		i++;
	}
}

void	ft_flood_fill(t_sl *sl, int pl_pos_x, int pl_pos_y)
{
	char	pos;

	pos = sl->map_cpy[pl_pos_y][pl_pos_x];
	if (pos != '1' && pos != 'F' && pos != 'X')
	{
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
		perror("Error with player");	//NEED EXIT
	}
	if (sl->exit_num != 1)
	{
		perror("Error with exit");	//NEED EXIT
	}
	if (sl->chest_num < 1)
	{
		perror("Error with chests");	//NEED EXIT
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
				ft_printf("unrecognized element: %c\n", sl->map_splited[i][j]); //NEED EXIT
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
			perror("Not rectangle"); //NEED EXIT
		i++;
	}
	ft_check_elemnts(sl);
	ft_check_counts(sl);
	ft_check_win(sl);
}

char    *ft_read_file(const char *file)
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
	if (fsize == 0)
		perror("Empty map");
	close(fd);
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
    sl->map_string = ft_read_file(file);
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
    if (file[size - 1] == 'r' && file[size - 2] == 'e' 
        && file[size - 3] == 'b' && file[size - 4] == '.')
        return (1);
    return (0);
}

void	ft_load_textures(t_sl *sl)
{
	mlx_texture_t	*img;

	img = mlx_load_png("./textures/player.npg");
	sl->player = mlx_texture_to_image(sl->mlx, img);
	mlx_delete_texture(img);
	img = mlx_load_png("./textures/enemy.npg");
	sl->enemy = mlx_texture_to_image(sl->mlx, img);
	mlx_delete_texture(img);
	img = mlx_load_png("./textures/chest.npg");
	sl->chest = mlx_texture_to_image(sl->mlx, img);
	mlx_delete_texture(img);
	img = mlx_load_png("./textures/floor.npg");
	sl->floor = mlx_texture_to_image(sl->mlx, img);
	mlx_delete_texture(img);
	img = mlx_load_png("./textures/exit.npg");
	sl->exit = mlx_texture_to_image(sl->mlx, img);
	mlx_delete_texture(img);
	img = mlx_load_png("./textures/wall.npg");
	sl->wall = mlx_texture_to_image(sl->mlx, img);
	mlx_delete_texture(img);
	
}
/*
void	ft_generate_map(t_sl *sl)
{
	
}

void	ft_run_game(t_sl *sl)
{
	ft_generate_map(sl);
}

*/

int main (int argc, char **argv)
{
    t_sl    *sl;
    sl = malloc(sizeof(t_sl));
    if (!sl)
        return (perror("Malloc error"),1);
    if (argc != 2)
        return (perror("Argument error"),1);
    ft_ini(sl);
    if (ft_check_ber(argv[1]) == 1)
    {
        ft_read_map(argv[1], sl);
		ft_check_map(sl);
		sl->mlx = mlx_init(sl->width * 64, sl->height * 64, "so_long", false);
		//ft_run_game(sl);
	}
    return (printf("altura: %i\nancho: %i\nplayers: %i\nchests: %i\nexit: %i\nplayer pos: %i,%i ", sl->height, sl->width, sl->player_num, sl->chest_num, sl->exit_num, sl->player_pos_x, sl->player_pos_y) ,0);

    /*
    mlx_t *sl;
    sl = mlx_init(128,128,"hola", false);
    return (perror("asgaefgafr"), 0);
    */
}