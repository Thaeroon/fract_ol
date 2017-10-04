/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:50:43 by nmuller           #+#    #+#             */
/*   Updated: 2017/10/04 21:37:50 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	init(t_img *img)
{
	img->offset_x = 0;
	img->offset_y = 0;
	img->zoom = 1;
	img->it_max = 127;
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

int		key_pressed(int key, void *parram)
{
	if(key == 65307)
		exit (0);
	else if (65361 <= key && key <= 65364)
		apply_offset(key, parram);
	else if (key == 65453)
		((t_img *)parram)->it_max -= 1;
	else if (key == 65451)
		((t_img *)parram)->it_max += 1;
	if ((65361 <= key && key <= 65364) || 65453 == key || key == 65451)
		draw(parram);
		printf("%i\n",key);
	return (0);
}

int		mouse_pressed(int key, int x, int y, void *parram)
{
	ft_printf("key = %i, x=%i, y=%i\n", key, x, y);
	if (key == 4)
		((t_img *)parram)->zoom *= 1.1;
	if (key == 5)
		((t_img *)parram)->zoom /= 1.1;
	if (key == 4 || key == 5)
	{
		((t_img *)parram)->offset_x = (x / (double)WIN_WIDTH / 2) - 0.5;
		((t_img *)parram)->offset_y = (y / (double)WIN_HEIGH / 2) - 0.5;
		printf("offset x = %f\noffset y = %f", ((t_img *)parram)->offset_x, ((t_img *)parram)->offset_y);
		draw(parram);
	}
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
	init(img);
	mlx_expose_hook(img->win, draw, img);
	mlx_hook(img->win, 2, 1L << 0, key_pressed, img);
	mlx_mouse_hook(img->win, mouse_pressed, img);
	mlx_loop(img->mlx);
	free(img);
	return (0);
}
