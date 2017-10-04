/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 06:24:27 by nmuller           #+#    #+#             */
/*   Updated: 2017/10/04 16:44:11 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		tooltip(const char *name)
{
	ft_printf("Usage : %s <fractale name>\n", name);
	ft_printf("fractales disponible : mandelbrot, julia\n");
	return (0);
}

int		get_input(char const *argv[], int argc)
{
	if (argc != 2)
		return (tooltip(argv[0]));
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		return (MANDE);
	if (ft_strcmp(argv[1], "julia") == 0)
		return (JULIA);
	return(tooltip(argv[0]));
}