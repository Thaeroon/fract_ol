/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 20:18:29 by nmuller           #+#    #+#             */
/*   Updated: 2017/10/06 18:16:35 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	put_pixel(t_img *img, int x, int y, int c)
{
	char	*ptr_color;

	if (img == NULL || x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGH)
		return ;
	ptr_color = img->buffer + (x * (img->bpp >> 3) + y * img->line_s);
	ptr_color[0] = (c >> 0x00) & 0xFF;
	ptr_color[1] = (c >> 0x08) & 0xFF;
	ptr_color[2] = (c >> 0x10) & 0xFF;
	ptr_color[3] = (c >> 0x18) & 0xFF;
}

int		draw(t_img *img)
{
	ft_bzero(img->buffer, WIN_WIDTH * WIN_HEIGH * (img->bpp >> 3));
	if (img->fract == MANDE)
		init_mande(img) && draw_mande(img);
	else if (img->fract == JULIA)
		init_julia(img) && draw_julia(img);
	if (img->fract == SHIP)
		init_ship(img) && draw_ship(img);
	else if (img->fract == TREE)
		draw_tree(img);
	mlx_put_image_to_window(img->mlx, img->win, img->ptr, 0, 0);
	if (img->mouse_state == 1)
		mlx_string_put(img->mlx, img->win, 0, 0, WHITE, "cursor = ensemble");
	else
		mlx_string_put(img->mlx, img->win, 0, 0, WHITE, "cursor = zoom");
	mlx_string_put(img->mlx, img->win, 0, 11, WHITE, ft_sprintf(
		"zoom = %i, precision = %i, color = %i",
		(int)(img->zoom * 1000), img->it_max, img->color));
	if (img->fract == JULIA)
		mlx_string_put(img->mlx, img->win, 0, 22, WHITE, ft_sprintf(
"ensemble : r = %i, i = %i", (int)(img->c_r * 1000), (int)(img->c_i * 1000)));
	return (0);
}

int		set_color(t_img *img, int i, int it_max)
{
	if (i < it_max)
		return (i * 0x00ffffff / img->color);
	return (0);
}
