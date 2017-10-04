/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 21:11:18 by nmuller           #+#    #+#             */
/*   Updated: 2017/10/04 14:07:04 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		get_c(t_point p0, t_point p1, int dx, int dy)
{
	float	avx;
	float	avy;
	float	av;
	float	dxy;

	if (p0.color == p1.color)
		return (p0.color);

	avx = abs(p1.x - p0.x);
	avy = abs(p1.y - p0.y);
	av = sqrt(avx * avx + avy * avy);
	dxy = sqrt(dx * dx + dy * dy);
	av = av / dxy;
	if (av > 0.5)
			return (p0.color);
	else
			return (p1.color);
}

int		get_z(t_point p0, t_point p1, int dx, int dy)
{
	float	avx;
	float	avy;
	float	av;
	float	dxy;

	if (p0.z == p1.z)
		return (p0.z);

	avx = abs(p1.x - p0.x) - dx;
	avy = abs(p1.y - p0.y) - dy;
	av = sqrt(avx * avx + avy * avy);
	dxy = sqrt(dx * dx + dy * dy);
	av = av / dxy;
	if (p0.z < p1.z)
		return (av * abs(p0.z - p1.z) + p0.z);
	return((1 - av) * abs(p0.z - p1.z) + p1.z);
}
