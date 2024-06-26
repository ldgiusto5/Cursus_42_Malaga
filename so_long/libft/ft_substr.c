/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:21:21 by ldi-gius          #+#    #+#             */
/*   Updated: 2024/04/01 04:19:04 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create_str_substr(char const *s, unsigned int start,
	size_t len, size_t i)
{
	char	*array;

	array = (char *)malloc(len * sizeof(char) + 1);
	if (array)
	{
		while (i < len)
		{
			array[i] = s[start + i];
			i++;
		}
		array[i] = '\0';
		return (array);
	}
	else
		free(array);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*array;

	if (start >= (unsigned int)ft_strlen(s))
	{
		array = (char *)malloc(1);
		if (!array)
		{
			free(array);
			return (0);
		}
		array[0] = '\0';
		return (array);
	}
	if (len > ((size_t)ft_strlen(s) - start))
		len = (size_t)ft_strlen(s) - start;
	array = ft_create_str_substr(s, start, len, 0);
	return (array);
}
