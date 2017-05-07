/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:00:15 by gbrochar          #+#    #+#             */
/*   Updated: 2016/05/26 15:16:23 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		check_mandelbrot(char *str)
{
	char	*mandelbrot;

	mandelbrot = ft_strnew(10);
	mandelbrot = "mandelbrot";
	if (ft_strcmp(mandelbrot, str) == 0)
		return (1);
	return (0);
}

int		check_julia(char *str)
{
	char	*julia;

	julia = ft_strnew(10);
	julia = "julia";
	if (ft_strcmp(julia, str) == 0)
		return (1);
	return (0);
}

int		check_black_hole(char *str)
{
	char	*black_hole;

	black_hole = ft_strnew(10);
	black_hole = "black_hole";
	if (ft_strcmp(black_hole, str) == 0)
		return (1);
	return (0);
}

int		check_arg(char *arg)
{
	if (check_mandelbrot(arg))
		return (1);
	if (check_julia(arg))
		return (2);
	if (check_black_hole(arg))
		return (3);
	return (0);
}
