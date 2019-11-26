/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:33:47 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/10/31 14:34:21 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scroll_up(int x, int y, t_win *win)
{
	win->fract->x_coef = (x / win->fract->scale + win->fract->x_coef) -
			((win->fract->scale * SCALE_STEP) / 2);
	win->fract->x_coef += (win->fract->scale * SCALE_STEP / 2) -
			(x / (win->fract->scale * SCALE_STEP));
	win->fract->y_coef = (y / win->fract->scale + win->fract->y_coef) -
			((win->fract->scale * SCALE_STEP) / 2);
	win->fract->y_coef += ((win->fract->scale * SCALE_STEP) / 2) -
			(y / (win->fract->scale * SCALE_STEP));
	win->fract->scale *= SCALE_STEP;
}

int		scroll_motion(int button, int x, int y, t_win *win)
{
	if (button == 5)
		scroll_up(x, y, win);
	else if (button == 4)
	{
		win->fract->x_coef = (x / win->fract->scale + win->fract->x_coef) -
				((win->fract->scale / SCALE_STEP) / 2);
		win->fract->x_coef += ((win->fract->scale / SCALE_STEP) / 2) -
				(x / (win->fract->scale / SCALE_STEP));
		win->fract->y_coef = (y / win->fract->scale + win->fract->y_coef)
				- ((win->fract->scale / SCALE_STEP) / 2);
		win->fract->y_coef += ((win->fract->scale / SCALE_STEP) / 2)
				- (y / (win->fract->scale / SCALE_STEP));
		win->fract->scale /= SCALE_STEP;
	}
	make_fractal(win->fract_type, win);
	return (0);
}

void	change_color(t_win *win, int key)
{
	if (key == 69)
	{
		win->fract->red += 1;
		win->fract->green += 1;
		win->fract->blue += 1;
		put_img(win);
	}
	else if (key == 78)
	{
		win->fract->red -= 1;
		win->fract->green -= 1;
		win->fract->blue -= 1;
		put_img(win);
	}
}

int		move_fractal(int key, t_win *win)
{
	if (key == 123)
		win->fract->x_coef += 0.02;
	else if (key == 124)
		win->fract->x_coef -= 0.02;
	else if (key == 125)
		win->fract->y_coef -= 0.02;
	else if (key == 126)
		win->fract->y_coef += 0.02;
	else if (key == 27)
		win->fract->iterations -= 2;
	else if (key == 24)
		win->fract->iterations += 2;
	else if (key == 69 || key == 78)
	{
		change_color(win, key);
		return (0);
	}
	make_fractal(win->fract_type, win);
	return (0);
}

int		key_check(int key, t_win *win)
{
	if (key == 53)
		exit(0);
	if (key == 15)
		set_default(win, win->fract);
	if (key == 0)
	{
		win->keys.anime_fl = 1;
		win->keys.space = 1;
	}
	if (key == 1)
	{
		win->fract->x_coef = -1.8;
		win->fract->y_coef = -1.2;
		win->keys.anime_fl = 0;
		win->fract->julia_x = -1;
		win->fract->julia_y = H / 2;
		win->keys.space = 0;
	}
	if (key == 49)
		win->keys.space = win->keys.space ? 0 : 1;
	return (0);
}
