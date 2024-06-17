/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-gius <ldi-gius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:22:22 by ldi-gius          #+#    #+#             */
/*   Updated: 2023/04/26 12:11:37 by ldi-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	count;
	int	b;

	i = 0;
	count = 0;
	b = 0;
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

static char	**ft_fill_array(char **str2, char *str, int n, char c)
{
	int	i;

	i = 0;
	while (i < n && *str)
	{
		while (*str == c && *str)
			str++;
		str2[i] = ft_fill_str(str, c);
		if (!str2[i])
		{
			ft_free_all(str2);
			return (NULL);
		}
		i++;
		while (*str != c && *str)
			str++;
	}
	str2[i] = 0;
	return (str2);
}

char	**ft_split(char const *s, char c)
{
	char	**str2;
	char	*str;
	int		n;
	int		i;

	i = 0;
	str = (char *) s;
	n = ft_countwords(str, c);
	str2 = (char **)malloc(sizeof(char *) * (n + 1));
	if (!str2)
	{
		free(str2);
		return (NULL);
	}
	str2 = ft_fill_array(str2, str, n, c);
	return (str2);
}
/*
int	main (void)
{
	char	**str;
	int	i = 0;
	str = ft_split("\t\t\t\thello!\t\t\t\t", '\t');
	while (i < 2)
	{
		printf("%s\n",str[i]);
		i++;
	}
	//	printf("%i\n",n);
	return (0);
}
*/