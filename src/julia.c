/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:33:36 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/10/31 14:30:00 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_anime_count(t_win *win, int x_ch, int y_ch)
{
	win->fract->k = complex_init(4
			* ((double)win->fract->julia_x / W - 0.5),
		4 * ((double)(H - win->fract->julia_y) / H - 0.5));
	create_julia(win, win->fract);
	win->fract->julia_x += x_ch;
	win->fract->julia_y += y_ch;
}

int		julia_anime(t_win *win)
{
	if (!win->keys.anime_fl)
		return (0);
	else
	{
		if (!win->keys.a_1step && (win->fract->julia_x < W - (W / 3)))
		{
			julia_anime_count(win, 2, 0);
			return (0);
		}
		win->keys.a_1step = 1;
		if (!win->keys.a_2step && (win->fract->julia_y > H - 3 * (H / 4)))
		{
			julia_anime_count(win, -2, -2);
			return (0);
		}
		win->keys.a_2step = 1;
		if (win->fract->julia_x > 0)
		{
			julia_anime_count(win, -2, (win->fract->julia_y != H / 2) ? 2 : 0);
			return (0);
		}
		win->keys.a_1step = 0;
		win->keys.a_2step = 0;
	}
	return (0);
}

int		julia_motion(int x, int y, t_win *win)
{
	if (win->keys.space)
		return (0);
	win->fract->k = complex_init(4 * ((double)x / W - 0.5),
		4 * ((double)(H - y) / H - 0.5));
	create_julia(win, win->fract);
	return (0);
}

void	create_julia(t_win *win, t_fractol *f)
{
	double	tempx;
	int		x;
	int		y;
	int		count;

	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W && !(count = 0))
		{
			f->z = complex_init(((double)x / f->scale + f->x_coef),
					((double)y / f->scale + f->y_coef));
			while ((f->z.re * f->z.re + f->z.im * f->z.im <= 4)
					&& (count < f->iterations))
			{
				tempx = f->z.re * f->z.re - f->z.im * f->z.im + f->k.re;
				f->z.im = 2 * f->z.re * f->z.im + f->k.im;
				f->z.re = tempx;
				count = count + 1;
			}
			win->colors[x + W * y] = count;
		}
	}
	put_img(win);
}
