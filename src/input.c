/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 06:24:27 by nmuller           #+#    #+#             */
/*   Updated: 2017/10/09 15:32:06 by nmuller          ###   ########.fr       */
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
	if (key == 123)
		img->offset_x -= 0.05 / img->zoom;
	else if (key == 124)
		img->offset_x += 0.05 / img->zoom;
	else if (key == 125)
		img->offset_y += 0.05 / img->zoom;
	else if (key == 126)
		img->offset_y -= 0.05 / img->zoom;
}

void	ft_zoom(t_img *img, int plus)
{
	if (plus == 1)
	{
		img->zoom *= 1.1;
		img->it_max += 1;
	}
	else if (img->zoom > 1.0)
	{
		img->zoom /= 1.1;
		if (img->it_max > 0)
			img->it_max -= 1;
	}
}
