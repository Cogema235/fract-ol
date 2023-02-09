/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:01:05 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/06 19:02:47 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdint.h>
# include "libft/libft.h"
# include "complex.h"
# include "julia.h"
# include "mendelbrot.h"
# include "render.h"
# include "math.h"

# define DEFAULT_WINDOW_SIZE 1000
# define MENDELBROT_DEFAULT_REMIN -2
# define MENDELBROT_DEFAULT_REMAX 1
# define MENDELBROT_DEFAULT_IMMIN -1.5
# define MENDELBROT_DEFAULT_IMMAX 1.5
# define JULIA_DEFAULT_REMIN -2
# define JULIA_DEFAULT_REMAX 2
# define JULIA_DEFAULT_IMMIN -2
# define JULIA_DEFAULT_IMMAX 2
# define DEFAULT_ITER_MAX 100
# define DEFAULT_BRIGHTNESS 1
# define MIN_SIMPLIFYING_SIZE 35
# define WIN_TITLE "fract-ol"
# define K_W 65362
# define K_A 65361
# define K_S 65364
# define K_D 65363
# define K_ESC 65307
# define K_O 111
# define K_I 105
# define K_K 107
# define K_C 99
# define K_R 114
# define K_G 103
# define K_B 98
# define K_L 108
# define K_M 109
# define K_P 112
# define K_N 110
# define K_J 106
# define M_LEFT 1
# define M_RIGHT 3
# define M_SCROLL_UP 4
# define M_SCROLL_DOWN 5

# define DTP 30

typedef struct s_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_color;

typedef struct s_fractol
{
	t_complex	c;
	t_complex	left_down_lim;
	t_complex	righ_top_lim;
	t_render	render;
	uint32_t	max_iter;
	uint8_t		fractal_id;
	t_color		color;
	double		dp;
	double		csize;
	int8_t		show_opt;
	int8_t		updatec;
	int			(*convergence)(struct s_fractol *, t_complex);
	int			(*iter2color)(struct s_fractol *, uint32_t iter);
}	t_fractol;

void	init_fractol(t_fractol *fractol, \
		int fractal_type, t_complex c, int8_t updatec);
void	reset(t_fractol *fractol);
void	set_render_limits(t_fractol *fractol, t_complex left_down, \
		t_complex righ_top);
void	update_dp(t_fractol *fractol);
void	render_square(t_fractol *fractol, int i0, int j0, int l);
void	render_square_force(t_fractol *fractol, int i0, int j0, int l);
void	init_mendelbrot(t_fractol *fractol);
void	init_julia(t_fractol *fractol);
void	set_fractal(t_fractol *fractol, int type);
void	updatec(t_fractol *fractol);
void	zoom(t_fractol *fractol, int factor);
void	translate_view(t_fractol *fractol, int dx, int dy);
void	zoom(t_fractol *fractol, int factor);
void	translate_event(t_fractol *fractol, int key);
int		update_render(t_fractol *fractol);
int		render_square_outline(t_fractol *fractol, int i0, int j0, int l);
int		render_hline(t_fractol *fractol, int i0, int j, int l);
int		render_vline(t_fractol *fractol, int i, int j0, int l);
int		mendelconv(t_fractol *fractol, t_complex z);
int		juliaconv(t_fractol *fractol, t_complex z);
int		key_event(int key, t_fractol *fractol);
int		mouse_event(int button, int x, int y, t_fractol *fractol);
void	colorevent(t_fractol *fractol, int key);
int		droprgb(t_fractol *fractol, uint32_t iter);
int		blackonwhite(t_fractol *fractol, uint32_t iter);
int		lsd(t_fractol *fractol, uint32_t iter);

#endif
