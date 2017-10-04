/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 06:24:27 by nmuller           #+#    #+#             */
/*   Updated: 2017/10/04 14:12:44 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

char	*tooltip(const char *name)
{
	ft_printf("Usage : %s <fractale name>\n", name);
	ft_printf("fractales disponible : mandelbrot, julia\n");
	return (0);
}

const char	*get_input(char const *argv[], int argc)
{
	return (((argc == 2) &&
		(ft_strcmp(argv[1], "mandelbrot") == 0
		|| ft_strcmp(argv[1], "julia") == 0)
							? argv[1] : tooltip(argv[0])));
}
