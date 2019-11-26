/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 13:22:15 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/10/29 20:48:50 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		create_mandelbrot(t_win *win, t_fractol *f)
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
			f->c = complex_init(((double)x / f->scale + f->x_coef),
					((double)y / f->scale + f->y_coef));
			f->z = complex_init(0, 0);
			while ((f->z.re * f->z.re + f->z.im * f->z.im <= 4)
					&& (count++ < f->iterations))
			{
				tempx = f->z.re * f->z.re - f->z.im * f->z.im + f->c.re;
				f->z.im = 2 * f->z.re * f->z.im + f->c.im;
				f->z.re = tempx;
			}
			win->colors[x + W * y] = count;
		}
	}
	put_img(win);
}
