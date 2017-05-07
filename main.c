/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 00:01:39 by gbrochar          #+#    #+#             */
/*   Updated: 2016/05/30 11:52:04 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init_mlx(t_env *e)
{
	if (!(e->ptr = mlx_init()))
		return (1);
	if (!(e->win = mlx_new_window(e->ptr, WINX, WINY, "fractol")))
	{
		free(e->ptr);
		return (1);
	}
	if (!(e->img = mlx_new_image(e->ptr, WINX, WINY)))
	{
		mlx_destroy_window(e->ptr, e->win);
		free(e->ptr);
		return (1);
	}
	if (!(e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sz_l, &e->endian)))
	{
		mlx_destroy_image(e->ptr, e->img);
		mlx_destroy_window(e->ptr, e->win);
		free(e->ptr);
		return (1);
	}
	e->sz_i = ft_strlen(e->data);
	mlx_hook(e->win, 2, 1L << 1, key_hook, e);
	mlx_hook(e->win, 6, 1L << 1, cursor_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	return (0);
}

void	init_env(t_env *e)
{
	int		i;

	i = -1;
	e->map = (t_map *)malloc(8 * sizeof(t_map));
	while (++i != 8)
		e->map[i].y_min = 180 * i;
	e->imax = 50;
	e->zoom = 1;
	e->zd_r = -2;
	e->zd_i = 2;
	e->lock = 0;
	e->julia_i = 0;
	e->julia_r = 0;
	e->os_i = 0;
	e->os_r = 0;
	e->r = 0;
	e->g = 2;
	e->b = 4;
}

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc == 2)
	{
		init_env(&(e));
		if (init_mlx(&e))
			ft_error("mlx_init failed");
		if ((e.fractal = check_arg(argv[1])) == 0)
		{
			ft_putstr("usage: ./fractol mandelbrot\n");
			ft_putstr("./fractol julia\n./fractol black_hole\n");
			exit(0);
		}
		draw(&e);
		mlx_loop(e.ptr);
	}
	else
	{
		ft_putstr("usage: ./fractol mandelbrot\n");
		ft_putstr("./fractol julia\n./fractol black_hole\n");
	}
	return (0);
}
