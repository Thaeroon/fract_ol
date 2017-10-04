/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 06:24:52 by nmuller           #+#    #+#             */
/*   Updated: 2017/10/05 01:12:31 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <stdio.h>

# include <math.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"

# define WIN_WIDTH 600
# define WIN_HEIGH 450
# define MANDE 1
# define JULIA 2

typedef struct	s_fract
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_fract;

typedef struct	s_img
{
	void		*ptr;
	char		*buffer;
	int			bpp;
	int			line_s;
	int			e;
	void		*win;
	void		*mlx;
	int			zoom_x;
	int			zoom_y;
	double		zoom;
	double		offset_x;
	double		offset_y;
	int			fract;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	int			it_max;
}				t_img;

int				get_input(char const *argv[], int argc);
int				draw(t_img *img);
int				init_mande(t_img *img);
int				draw_mande(t_img *img);
int				draw_julia(t_img *img);
void			put_pixel(t_img *img, int x, int y, int c);

#endif
