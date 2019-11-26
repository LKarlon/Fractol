/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:19:48 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/10/31 14:29:56 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# define H	480
# define W	720
# define MAX_ITER 50
# define SCALE_STEP 1.05

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_key
{
	int				motion_fl;
	int				anime_fl;
	int				a_1step;
	int				a_2step;
	int				space;
}					t_key;

typedef struct		s_fractol
{
	t_complex		min;
	t_complex		max;
	t_complex		factor;
	t_complex		c;
	t_complex		k;
	t_complex		z;
	double			red;
	double			green;
	double			blue;
	double			y_coef;
	double			x_coef;
	double			scale;
	int				iterations;
	int				julia_x;
	int				julia_y;
}					t_fractol;

typedef struct		s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				*img_ptr;
	int				*addr;
	char			*pl[2];
	int				fin[2];
	int				*colors;
	t_fractol		*fract;
	t_key			keys;
	int				fract_type;
}					t_win;

t_win				*win_init(char *s, int fract_type);
void				ft_alarm(char *error);
void				create_mandelbrot(t_win *win, t_fractol *f);
void				create_mandelbar(t_win *win, t_fractol *f);
void				create_chicken(t_win *win, t_fractol *f);
void				create_burning_ship(t_win *win, t_fractol *f);
int					key_check(int key, t_win *win);
void				put_img(t_win *win);
void				put_color_pix(t_win *win, int i);
void				create_julia(t_win *win, t_fractol *fract);
t_fractol			*fract_init(void);
t_complex			complex_init(double re, double im);
int					julia_motion(int x, int y, t_win *win);
void				hook_functions(t_win *win, int event);
int					scroll_motion(int button, int x, int y, t_win *win);
void				make_fractal(int fract_type, t_win *win);
int					move_fractal(int key, t_win *win);
void				set_default(t_win *win, t_fractol *fract);
int					julia_anime(t_win *win);
void				set_default(t_win *win, t_fractol *fract);

#endif
