/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 06:24:52 by nmuller           #+#    #+#             */
/*   Updated: 2017/10/06 18:09:06 by nmuller          ###   ########.fr       */
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

# define WIN_WIDTH 800
# define WIN_HEIGH 800
# define WHITE 0x00ffffff
# define MANDE 1
# define JULIA 2
# define SHIP 3
# define TREE 4

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

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
	double		r;
	double		i;
	double		c_r;
	double		c_i;
	int			it_max;
	int			mouse_state;
	int			color;
}				t_img;

int				get_input(char const *argv[], int argc);
int				draw(t_img *img);
int				init_mande(t_img *img);
int				draw_mande(t_img *img);
int				init_julia(t_img *img);
int				draw_julia(t_img *img);
int				init_ship(t_img *img);
int				draw_ship(t_img *img);
int				draw_tree(t_img *img);
void			put_pixel(t_img *img, int x, int y, int c);
int				set_color(t_img *img, int i, int it_max);
void			apply_offset(int key, t_img *img);
void			ft_zoom(t_img *img, int plus);

#endif
