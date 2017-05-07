/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 02:38:27 by gbrochar          #+#    #+#             */
/*   Updated: 2016/05/30 11:36:32 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_manage(t_env *e, int keycode)
{
	if (keycode == 16)
		e->r++;
	if (keycode == 32)
		e->g++;
	if (keycode == 34)
		e->b++;
	if (keycode == 4)
		e->r--;
	if (keycode == 38)
		e->g--;
	if (keycode == 40)
		e->b--;
	if (keycode == 18 || keycode == 19 || keycode == 20)
	{
		e->fractal = (keycode == 18) ? 1 : e->fractal;
		e->fractal = (keycode == 19) ? 2 : e->fractal;
		e->fractal = (keycode == 20) ? 3 : e->fractal;
		init_env(e);
	}
}

void	zoom_manage(t_env *e, int keycode)
{
	if (keycode == 69)
	{
		e->zoom *= 4;
		e->map[0].z_r = 720.0 / WINX * e->map[0].d_r + e->zd_r;
		e->map[0].z_i = 720.0 / WINY * e->map[0].d_i + e->zd_i;
		e->map[0].d_r = 4.0 / sqrt(e->zoom);
		e->map[0].d_i = -4.0 / sqrt(e->zoom);
		e->zd_r = -((720.0 * (e->map[0].d_r / WINX))) + e->map[0].z_r;
		e->zd_i = -((720.0 * ((e->map[0].d_i) / WINY))) + e->map[0].z_i;
		draw(e);
	}
	if (keycode == 78 && e->zoom >= 0.0001)
	{
		e->zoom /= 4;
		e->map[0].z_r = 720.0 / WINX * e->map[0].d_r + e->zd_r;
		e->map[0].z_i = 720.0 / WINY * e->map[0].d_i + e->zd_i;
		e->map[0].d_r = 4.0 / sqrt(e->zoom);
		e->map[0].d_i = -4.0 / sqrt(e->zoom);
		e->zd_r = -((720.0 * (e->map[0].d_r / WINX))) + e->map[0].z_r;
		e->zd_i = -((720.0 * ((e->map[0].d_i) / WINY))) + e->map[0].z_i;
		draw(e);
	}
}

int		key_hook(int keycode, void *e_void)
{
	t_env	*e;

	e = e_void;
	if (keycode == 53)
		exit(0);
	if (keycode == 15)
		e->imax *= 1.2;
	if ((keycode == 3) && e->imax > 4)
		e->imax /= 1.2;
	if (keycode == 13 || keycode == 126)
		e->os_i -= (double)0.25 / sqrt(e->zoom);
	if (keycode == 1 || keycode == 125)
		e->os_i += (double)0.25 / sqrt(e->zoom);
	if (keycode == 2 || keycode == 124)
		e->os_r -= (double)0.25 / sqrt(e->zoom);
	if (keycode == 0 || keycode == 123)
		e->os_r += (double)0.25 / sqrt(e->zoom);
	if (keycode == 37)
		e->lock = (e->lock == 0) ? 1 : 0;
	color_manage(e, keycode);
	zoom_manage(e, keycode);
	draw(e);
	return (0);
}

int		mouse_hook(int but, int x, int y, void *e_void)
{
	t_env	*e;

	e = (t_env *)e_void;
	if ((but == 1 || but == 4) && x > -1 && y > -1 && x < WINX && y < WINY)
	{
		e->zoom *= 4;
		e->map[0].z_r = (double)x / WINX * e->map[0].d_r + e->zd_r;
		e->map[0].z_i = (double)y / WINY * e->map[0].d_i + e->zd_i;
		e->map[0].d_r = (double)4 / sqrt(e->zoom);
		e->map[0].d_i = (double)-4 / sqrt(e->zoom);
		e->zd_r = -(((double)x * (e->map[0].d_r / WINX))) + e->map[0].z_r;
		e->zd_i = -(((double)y * ((e->map[0].d_i) / WINY))) + e->map[0].z_i;
	}
	if ((but == 2 || but == 5) && x > -1 && y > -1 && x < WINX && y < WINY)
	{
		e->zoom /= 4;
		e->map[0].z_r = (double)x / WINX * e->map[0].d_r + e->zd_r;
		e->map[0].z_i = (double)y / WINY * e->map[0].d_i + e->zd_i;
		e->map[0].d_r = (double)4 / sqrt(e->zoom);
		e->map[0].d_i = (double)-4 / sqrt(e->zoom);
		e->zd_r = -(((double)x * (e->map[0].d_r / WINX))) + e->map[0].z_r;
		e->zd_i = -(((double)y * ((e->map[0].d_i) / WINY))) + e->map[0].z_i;
	}
	draw(e);
	return (0);
}

int		cursor_hook(int x, int y, void *e_void)
{
	t_env	*e;

	e = (t_env *)e_void;
	if (e->lock == 0 && x > -1 && y > -1 && x < WINX && y < WINY)
	{
		e->map[y / 180].d_r = (double)4 / sqrt(e->zoom);
		e->map[y / 180].d_i = (double)-4 / sqrt(e->zoom);
		e->julia_r = (double)x / WINX * e->map[y / 180].d_r + e->zd_r;
		e->julia_i = (double)y / WINY * e->map[y / 180].d_i + e->zd_i;
		draw(e);
	}
	return (0);
}
