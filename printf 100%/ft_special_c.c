/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-gius <ldi-gius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:54:36 by ldi-gius          #+#    #+#             */
/*   Updated: 2023/05/12 21:18:36 by ldi-gius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_special_c(int c)
{
	write(1, &c, 1);
	return (1);
}

/*
int	main (void)
{
	ft_special_c('q');
	return (0);
}
*/