/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:13:49 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/10/30 22:03:24 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_alarm(char *error)
{
	ft_putstr(error);
	exit(0);
}

void	put_color_pix(t_win *win, int i)
{
	double	t;
	int		red;
	int		green;
	int		blue;
	int		final_color;

	t = (double)win->colors[i] / win->fract->iterations;
	red = (int)(win->fract->red * (1 - t) * pow(t, 3) * 255);
	green = (int)(win->fract->green * pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int)(win->fract->blue * pow((1 - t), 3) * t * 255);
	final_color = (red << 16) | (green << 8) | blue;
	if (win->colors[i] > win->fract->iterations)
		win->addr[i] = 0x000000;
	else
		win->addr[i] = final_color;
}

void	put_img(t_win *win)
{
	int i;

	i = 0;
	while (i < H * W)
		put_color_pix(win, i++);
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
}

void	set_default(t_win *win, t_fractol *fract)
{
	fract->scale = 200;
	fract->x_coef = -2.6;
	fract->y_coef = -1.2;
	fract->iterations = MAX_ITER;
	fract->red = 7;
	fract->green = 15;
	fract->blue = 8.5;
	make_fractal(win->fract_type, win);
}
