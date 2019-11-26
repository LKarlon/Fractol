/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:18:14 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/10/31 14:13:20 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		hook_functions(t_win *win, int event)
{
	if (event == 6)
	{
		mlx_hook(win->win_ptr, 6, 0, julia_motion, win);
		mlx_loop_hook(win->mlx_ptr, julia_anime, win);
	}
	mlx_hook(win->win_ptr, 4, 0, scroll_motion, win);
	mlx_hook(win->win_ptr, 2, 0, move_fractal, win);
	mlx_key_hook(win->win_ptr, key_check, win);
	mlx_loop(win->mlx_ptr);
}

void		make_fractal(int fract_type, t_win *win)
{
	if (fract_type == 1)
	{
		create_julia(win, win->fract);
		hook_functions(win, 6);
		return ;
	}
	if (fract_type == 2)
		create_mandelbrot(win, win->fract);
	if (fract_type == 3)
		create_burning_ship(win, win->fract);
	if (fract_type == 4)
		create_mandelbar(win, win->fract);
	if (fract_type == 5)
		create_chicken(win, win->fract);
	hook_functions(win, 0);
}

void		print_usage(char *argv)
{
	ft_printf("Usage: %s {name_of_fractal}\nAvailable parameters: %s",
	argv,
	"Julia, Mandelbrot, Burning_ship, Mandelbar, Chicken\n");
	exit(0);
}

int			main(int argc, char **argv)
{
	t_win	*win;
	int		fract_type;

	fract_type = 0;
	if (argc == 1 || argc > 2)
		print_usage(argv[0]);
	else
	{
		if (!ft_strcmp(argv[1], "Julia"))
			fract_type = 1;
		else if (!ft_strcmp(argv[1], "Mandelbrot"))
			fract_type = 2;
		else if (!ft_strcmp(argv[1], "Burning_ship"))
			fract_type = 3;
		else if (!ft_strcmp(argv[1], "Mandelbar"))
			fract_type = 4;
		else if (!ft_strcmp(argv[1], "Chicken"))
			fract_type = 5;
		else
			print_usage(argv[0]);
	}
	win = win_init("Fractal", fract_type);
	win->fract_type = fract_type;
	make_fractal(win->fract_type, win);
}
