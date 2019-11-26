/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:34:04 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/10/31 14:29:52 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		colors_init(t_win *win)
{
	if (!(win->colors = malloc(sizeof(int) * W * H)))
		ft_alarm("COLORS_INIT_ERROR");
}

t_complex	complex_init(double re, double im)
{
	t_complex	complex_digit;

	complex_digit.re = re;
	complex_digit.im = im;
	return (complex_digit);
}

t_fractol	*fract_init(void)
{
	t_fractol	*fract;

	if (!(fract = malloc(sizeof(t_fractol))))
		ft_alarm("ERROR_FRACT_INIT");
	fract->k = complex_init(-0.4, 0.6);
	fract->scale = 200;
	fract->x_coef = -2.6;
	fract->y_coef = -1.2;
	fract->iterations = MAX_ITER;
	fract->red = 7;
	fract->green = 15;
	fract->blue = 8.5;
	fract->julia_x = 0;
	fract->julia_y = H / 2;
	return (fract);
}

t_win		*win_init(char *s, int fract_type)
{
	t_win		*win;
	int			size;
	int			endian;
	int			bits;
	int			i;

	i = 0;
	if (!(win = (t_win*)malloc(sizeof(t_win))))
		ft_alarm("WIN_INIT_ERROR");
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, W, H, s);
	win->img_ptr = (int*)mlx_new_image(win->mlx_ptr, W, H);
	win->addr = (int*)mlx_get_data_addr(win->img_ptr, &bits, &size, &endian);
	colors_init(win);
	win->fract = fract_init();
	if (fract_type == 1)
	{
		win->fract->x_coef = -1.8;
		win->fract->y_coef = -1.2;
	}
	win->keys.a_1step = 0;
	win->keys.a_2step = 0;
	return (win);
}
