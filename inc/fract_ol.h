/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 06:24:52 by nmuller           #+#    #+#             */
/*   Updated: 2017/10/04 14:13:28 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <math.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"

# define WIN_WIDTH 800
# define WIN_HEIGH 800

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
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
	int			zoom;
	int			offset_x;
	int			offset_y;
	const char	*fract;
}				t_img;

const char		*get_input(char const *argv[], int argc);
int				draw(t_img *img);

#endif
