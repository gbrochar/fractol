/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_4_7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 00:36:52 by gbrochar          #+#    #+#             */
/*   Updated: 2016/05/26 00:46:41 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*draw_4(void *e_void)
{
	int		x;
	int		y;
	t_env	*e;

	e = (t_env *)e_void;
	y = 720;
	while (y != 900)
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

void	*draw_5(void *e_void)
{
	int		x;
	int		y;
	t_env	*e;

	e = (t_env *)e_void;
	y = 900;
	while (y != 1080)
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

void	*draw_6(void *e_void)
{
	int		x;
	int		y;
	t_env	*e;

	e = (t_env *)e_void;
	y = 1080;
	while (y != 1260)
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

void	*draw_7(void *e_void)
{
	int		x;
	int		y;
	t_env	*e;

	e = (t_env *)e_void;
	y = 1260;
	while (y != 1440)
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
