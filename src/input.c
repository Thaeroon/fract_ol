/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 06:24:27 by nmuller           #+#    #+#             */
/*   Updated: 2017/10/06 14:29:09 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		tooltip(const char *name)
{
	ft_printf("Usage : %s <fractale name>\n", name);
	ft_printf("fractales disponible : mandelbrot, julia, ship, tree\n");
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
	if (ft_strcmp(argv[1], "tree") == 0)
		return (TREE);
	if (ft_strcmp(argv[1], "ship") == 0)
		return (SHIP);
	return (tooltip(argv[0]));
}

void	apply_offset(int key, t_img *img)
{
	if (key == 65361)
		img->offset_x -= 0.05 / img->zoom;
	if (key == 65362)
		img->offset_y -= 0.05 / img->zoom;
	if (key == 65363)
		img->offset_x += 0.05 / img->zoom;
	if (key == 65364)
		img->offset_y += 0.05 / img->zoom;
}
