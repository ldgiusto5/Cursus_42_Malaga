/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:28:31 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/06/17 08:40:26 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_ini(t_sl *sl)
{
	sl->mlx = 0;
	sl->player = 0;
	sl->backg = 0;
	sl->wall = 0;
	sl->exit = 0;
	sl->enemy = 0;
	sl->chest = 0;
	sl->map_splited = 0;
	sl->map_string = 0;
	sl->height = 0;
	sl->width = 0;
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

    sl->map_string = ft_read_file(file);
    sl->map_splited = ft_split(sl->map_string, '\n');
    i = 0;
    i = 0;
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
    }
    return (perror("not .ber"),1);

    /*
    mlx_t *sl;
    sl = mlx_init(128,128,"hola", false);
    return (perror("asgaefgafr"), 0);
    */
}
    //mlx = mlx_init(128,128,"hola", false);
    //return (perror("asgaefgafr"), 0);
}
