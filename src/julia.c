/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:10:02 by nmuller           #+#    #+#             */
/*   Updated: 2017/10/06 14:21:08 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int			init_julia(t_img *img)
{
	img->x1 = img->r - 1.5 / img->zoom + img->offset_x;
	img->x2 = img->r + 1.5 / img->zoom + img->offset_x;
	img->y1 = img->i - 1.5 / img->zoom + img->offset_y;
	img->y2 = img->i + 1.5 / img->zoom + img->offset_y;
	return (1);
}

static void	iteration(t_img *img, int x, int y, int i)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;

	c_r = img->c_r;
	c_i = img->c_i;
	z_r = x / (double)img->zoom_x + img->x1;
	z_i = y / (double)img->zoom_y + img->y1;
	while (((z_r * z_r + z_i * z_i) < 4) && (++i < img->it_max))
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
	}
	put_pixel(img, x, y, set_color(i, img->it_max));
}

int			draw_julia(t_img *img)
{
	int		x;
	int		y;

	img->zoom_x = WIN_WIDTH / (img->x2 - img->x1);
	img->zoom_y = WIN_HEIGH / (img->y2 - img->y1);
	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGH)
			iteration(img, x, y, 0);
	}
	return (1);
}
