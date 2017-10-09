/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 12:18:26 by nmuller           #+#    #+#             */
/*   Updated: 2017/10/08 14:16:37 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void		draw_line(t_img *img, t_point p0, t_point p1, int err2)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;

	if (img == NULL
		|| p0.x < 0 || p0.y < 0 || p1.x >= WIN_WIDTH || p1.y >= WIN_HEIGH)
		return ;
	dx = abs(p1.x - p0.x);
	sx = p0.x < p1.x ? 1 : -1;
	dy = abs(p1.y - p0.y);
	sy = p0.y < p1.y ? 1 : -1;
	err = ((dx > dy) ? dx : -dy) / 2;
	while (p0.x != p1.x || p0.y != p1.y)
	{
		put_pixel(img, p0.x, p0.y, WHITE);
		err2 = err;
		if (err2 > -dx)
			((err -= dy) || 1) && (p0.x += sx);
		if (err2 < dy)
			((err += dx) || 1) && (p0.y += sy);
	}
}

static void	iteration(t_img *img, t_point a, t_point b, int times)
{
	t_point	c;
	t_point	d;
	t_point	e;

	c.x = b.x - (a.y - b.y);
	c.y = b.y - (b.x - a.x);
	d.x = a.x - (a.y - b.y);
	d.y = a.y - (b.x - a.x);
	e.x = d.x + (b.x - a.x - (a.y - b.y)) / 2;
	e.y = d.y - (b.x - a.x + a.y - b.y) / 2;
	if (times > 0)
	{
		draw_line(img, a, b, 0);
		draw_line(img, c, b, 0);
		draw_line(img, c, d, 0);
		draw_line(img, a, d, 0);
		iteration(img, d, e, times - 1);
		iteration(img, e, c, times - 1);
	}
}

int			draw_tree(t_img *img)
{
	t_point	a;
	t_point	b;
	double	side;

	side = 80;
	a.x = 6 * side / 2 - side / 2 + 60;
	a.y = 4 * side + 200;
	b.x = 6 * side / 2 + side / 2 + 60;
	b.y = 4 * side + 200;
	iteration(img, a, b, img->it_max);
	return (1);
}
