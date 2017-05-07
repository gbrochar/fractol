/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:17:03 by gbrochar          #+#    #+#             */
/*   Updated: 2016/05/30 09:18:09 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_env *e, int i, int x, int y)
{
	int		index;
	double	ct_index;

	ct_index = i + 1 - 2 * log(3) / sqrt((e->map[y / 180].z_r *
			e->map[y / 180].z_r) + (e->map[y / 180].z_i * e->map[y / 180].z_i));
	index = (x * (e->bpp / 8)) + (y * e->sz_l);
	if (i == e->imax)
	{
		e->data[index] = 0;
		e->data[index + 1] = 0;
		e->data[index + 2] = 0;
	}
	else
	{
		e->data[index] = (sin(0.1 * ct_index + e->r) * 50 + 200);
		e->data[index + 1] = (sin(0.1 * ct_index + e->g) * 50 + 200);
		e->data[index + 2] = (sin(0.1 * ct_index + e->b) * 50 + 200);
	}
}
