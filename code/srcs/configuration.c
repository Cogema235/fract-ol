/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:11:24 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/06 18:26:21 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_fractol(t_fractol *fractol,
	int fractal_type, t_complex c, int8_t updatec)
{
	fractol->csize = 0;
	fractol->iter2color = lsd;
	fractol->color.r = 3;
	fractol->color.g = 1;
	fractol->color.b = 5;
	fractol->c = c;
	fractol->updatec = updatec;
	fractol->show_opt = 1;
	fractol->fractal_id = fractal_type;
	fractol->max_iter = DEFAULT_ITER_MAX;
	init_render(&(fractol->render), DEFAULT_WINDOW_SIZE, WIN_TITLE);
	set_fractal(fractol, fractal_type);
	define_event(&fractol->render, event(17, 1L << 2, \
				kill_render, &fractol->render));
	define_event(&fractol->render, event(4, 1L << 2, mouse_event, fractol));
	define_event(&fractol->render, event(2, 1L << 0, key_event, fractol));
	set_update(&fractol->render, update_render, fractol);
	update_dp(fractol);
	update_render(fractol);
	start_loop(&fractol->render);
}

void	set_fractal(t_fractol *fractol, int type)
{
	if (type == 0)
		init_mendelbrot(fractol);
	else if (type == 1)
		init_julia(fractol);
	else
		exit(0);
}

void	init_mendelbrot(t_fractol *fractol)
{
	fractol->convergence = mendelconv;
	set_render_limits(fractol, complex(MENDELBROT_DEFAULT_REMIN, \
		MENDELBROT_DEFAULT_IMMIN), complex(MENDELBROT_DEFAULT_REMAX, \
		MENDELBROT_DEFAULT_IMMAX));
}

void	init_julia(t_fractol *fractol)
{
	fractol->convergence = juliaconv;
	set_render_limits(fractol, complex(JULIA_DEFAULT_REMIN, \
		JULIA_DEFAULT_IMMIN), complex(JULIA_DEFAULT_REMAX, \
		JULIA_DEFAULT_IMMAX));
}

void	set_render_limits(t_fractol *fractol, t_complex left_down, \
	t_complex righ_top)
{
	fractol->left_down_lim = left_down;
	fractol->righ_top_lim = righ_top;
}
