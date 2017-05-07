/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:06:48 by gbrochar          #+#    #+#             */
/*   Updated: 2016/05/30 03:11:43 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	compute(int x, int y, t_env *e)
{
	if (e->fractal == 1)
		mandelbrot_compute(x, y, e);
	if (e->fractal == 2)
		julia_compute(x, y, e);
	if (e->fractal == 3)
		black_hole_compute(x, y, e);
}
