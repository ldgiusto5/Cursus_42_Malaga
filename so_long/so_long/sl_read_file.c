/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:04:07 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/06/20 15:38:37 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_ber(const char *file)
{
	int	size;

	size = ft_strlen(file);
	if (size > 4)
	{
		if (file[size - 1] == 'r' && file[size - 2] == 'e'
			&& file[size - 3] == 'b' && file[size - 4] == '.')
			return (1);
	}
	return (0);
}

char	*ft_read_file(const char *file, t_sl *sl)
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

void	ft_read_map(const char *file, t_sl *sl)
{
	int	i;
	int	j;

	i = 0;
	sl->map_string = ft_read_file(file, sl);
	sl->map_splited = ft_split(sl->map_string, '\n');
	sl->map_cpy = ft_split(sl->map_string, '\n');
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
