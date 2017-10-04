/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:31:19 by nmuller           #+#    #+#             */
/*   Updated: 2016/11/07 15:30:19 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ret;
	char	*zeroing;
	size_t	cpt;

	cpt = 0;
	if (!(ret = malloc(size)))
		return (NULL);
	zeroing = (char*)ret;
	while (cpt < size)
		zeroing[cpt++] = 0;
	return (ret);
}
