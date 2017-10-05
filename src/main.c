/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:50:43 by nmuller           #+#    #+#             */
/*   Updated: 2017/10/05 15:12:08 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	init(t_img *img)
{
	img->offset_x = 0;
	img->offset_y = 0;
	img->zoom = (img->fract == TREE) ? 100 : 1;
	img->it_max = (img->fract == TREE) ? 1 : 127;
	img->r = (img->fract == MANDE) ? -0.5 : 0;
	img->i = 0;
	img->mouse_state = 0;
	img->c_r = -0.25;
	img->c_i = -0.66;
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
	t_img	*img;

	img = (t_img *)parram;
	if(key == 65307)
		exit (0);
	else if (65361 <= key && key <= 65364)
		apply_offset(key, parram);
	else if (key == 65453)
		img->it_max -= 1;
	else if (key == 65451)
		img->it_max += 1;
	else if (key == 97)
		img->mouse_state = 0;
	else if (key == 122)
		img->mouse_state = 1;
	else if (key == 101)
		img->mouse_state = 2;
	if ((65361 <= key && key <= 65364) || 65453 == key || key == 65451
							|| key == 97 || key == 122 || key == 101)
		draw(parram);
		ft_printf("%i\n",key);
	return (0);
}

int		mouse_pressed(int key, int x, int y, void *parram)
{
	t_img	*img;

	img = (t_img*)parram;
	if (key == 4)
		img->zoom *= 1.1;
	if (key == 5)
		img->zoom /= 1.1;
	if (key == 4 || key == 5)
	{
		if (img->mouse_state == 1)
		{
			img->r = (x * (img->x2 - img->x1)) / WIN_WIDTH + img->x1;
			img->i = (y * (img->y2 - img->y1)) / WIN_HEIGH + img->y1;
		}
		printf("key = %i, x=%i r=%f, y=%i i=%f\n", key, x, img->r, y, img->i);
		draw(parram);
	}
	return (0);
}

int		mouse_moved(int x, int y, void *parram)
{
	t_img	*img;

	img = (t_img *)parram;
	if (img->mouse_state == 2)
	{
		img->c_r = x * 2.0 / (double)WIN_WIDTH -1.0;
		img->c_i = y * 2.0 / (double)WIN_HEIGH -1.0;
		draw(img);
	}
	return (0);
}

int		main(int argc, char const *argv[])
{
	t_img	*img;

	(!(img = (t_img*)malloc(sizeof(t_img)))) ? exit(-1) : 0;
	(img->fract = get_input(argv, argc)) ? 0 : exit(1);
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, WIN_WIDTH, WIN_HEIGH, (char*)argv[1]);
	img->ptr = mlx_new_image(img->mlx, WIN_WIDTH, WIN_HEIGH);
	img->buffer = mlx_get_data_addr(img->ptr, &(img->bpp), &(img->line_s),
																	&(img->e));
	init(img);

	mlx_expose_hook(img->win, draw, img);
	mlx_hook(img->win, 2, 1L << 0, key_pressed, img);
	mlx_hook(img->win, 6 , 1L << 6, mouse_moved, img);
	mlx_mouse_hook(img->win, mouse_pressed, img);
	mlx_loop(img->mlx);
	free(img);
	return (0);
}
