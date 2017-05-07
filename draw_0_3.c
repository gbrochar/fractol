/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_0_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 00:36:26 by gbrochar          #+#    #+#             */
/*   Updated: 2016/05/26 00:43:18 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*draw_0(void *e_void)
{
	int		x;
	int		y;
	t_env	*e;

	e = (t_env *)e_void;
	y = 0;
	while (y != 180)
	{
		x = 0;
		while (x != WINX)
		{
			compute(x, y, e);
			++x;
		}
		++y;
	}
	return (e_void);
}

void	*draw_1(void *e_void)
{
	int		x;
	int		y;
	t_env	*e;

	e = (t_env *)e_void;
	y = 180;
	while (y != 360)
	{
		x = 0;
		while (x != WINX)
		{
			compute(x, y, e);
			++x;
		}
		++y;
	}
	return (e_void);
}

void	*draw_2(void *e_void)
{
	int		x;
	int		y;
	t_env	*e;

	e = (t_env *)e_void;
	y = 360;
	while (y != 540)
	{
		x = 0;
		while (x != WINX)
		{
			compute(x, y, e);
			++x;
		}
		++y;
	}
	return (e_void);
}

void	*draw_3(void *e_void)
{
	int		x;
	int		y;
	t_env	*e;

	e = (t_env *)e_void;
	y = 540;
	while (y != 720)
	{
		x = 0;
		while (x != WINX)
		{
			compute(x, y, e);
			++x;
		}
		++y;
	}
	return (e_void);
}
