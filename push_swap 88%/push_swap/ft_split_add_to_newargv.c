/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_add_to_newargv.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-gius <ldi-gius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:22:22 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/05/22 16:19:50 by ldi-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	count;
	int	b;

	i = 0;
	count = 0;
	b = 0;
	if (s[0] == '\0')
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (b == 0)
			{
				count++;
				b = 1;
			}
		}
		else
			b = 0;
		i++;
	}
	return (count);
}

static char	*ft_fill_str(char *str, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	word = (char *)malloc(i + 1);
	if (!word)
	{
		free(word);
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static void	ft_free_all(char **str2)
{
	int	i;

	i = 0;
	while (str2[i] != NULL)
	{
		free(str2[i]);
		i++;
	}
	free(str2);
}

void	ft_fill_array(t_stacks *stacks, char *str, char c)
{
	while (stacks->i < stacks->n && *str)
	{
		while (*str == c && *str)
			str++;
		stacks->newargv[stacks->i] = ft_fill_str(str, c);
		if (!stacks->newargv[stacks->i])
		{
			ft_free_all(stacks->newargv);
			return ;
		}
		stacks->i++;
		while (*str != c && *str)
			str++;
	}
	stacks->newargv[stacks->i] = 0;
	return ;
}

int	ft_split_add_to_newargv(char **argv, char c, t_stacks *stacks)
{
	int		i;

	stacks -> n = 0;
	i = 0;
	while (argv[i] != NULL)
	{
		if (ft_countwords(argv[i], c) == -1)
			return (ft_printf("Error\n"), 1);
		stacks -> n = stacks -> n + ft_countwords(argv[i], c);
		i++;
	}
	i = 0;
	stacks -> newargv = (char **)malloc(sizeof(char *) * (stacks -> n + 1));
	if (!stacks -> newargv)
		return (free(stacks -> newargv), 1);
	stacks->i = 0;
	while (argv[i] != NULL)
	{
		ft_fill_array(stacks, argv[i], c);
		i++;
	}
	return (0);
}
