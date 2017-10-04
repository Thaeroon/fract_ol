/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:50:43 by nmuller           #+#    #+#             */
/*   Updated: 2017/10/04 14:14:09 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	apply_offset(int key, t_img *img)
{
	if (key == 65361)
		img->offset_x -= img->zoom;
	if (key == 65362)
		img->offset_y -= img->zoom;
	if (key == 65363)
		img->offset_x += img->zoom;
	if (key == 65364)
		img->offset_y += img->zoom;
}

int		key_pressed(int key, void *parram)
{
	if(key == 65307)
		exit (0);
	else if (65361 <= key && key <= 65364)
		apply_offset(key, parram);
	else if (key == 112)
		((t_img *)parram)->zoom += 1;
	else if (key == 109)
		((t_img *)parram)->zoom -= 1;
	if ((65361 <= key && key <= 65364) || 109 == key || key == 112)
		draw(parram);
	return (0);
}

int		main(int argc, char const *argv[])
{
	t_img	*img;

	(!(img = (t_img*)malloc(sizeof(t_img)))) ? exit(-1) : 0;
	(img->fract = get_input(argv, argc)) ? 0 : exit(1);
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, WIN_WIDTH, WIN_HEIGH, "fract_ol");
	img->ptr = mlx_new_image(img->mlx, WIN_WIDTH, WIN_HEIGH);
	img->buffer = mlx_get_data_addr(img->ptr, &(img->bpp), &(img->line_s),
																	&(img->e));
	mlx_expose_hook(img->win, draw, img);
	mlx_key_hook(img->win, key_pressed, img);
	mlx_loop(img->mlx);
	free(img);
	return (0);
}
