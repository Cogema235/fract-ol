/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:07:12 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/06 19:21:19 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	key_event(int key, t_fractol *fractol)
{
	if (key == K_ESC)
		kill_render(&fractol->render);
	else if (key == K_N)
		reset(fractol);
	else if (key == K_W || key == K_A || key == K_S || key == K_D)
		translate_event(fractol, key);
	else if (key == K_O)
		fractol->show_opt *= -1;
	else if (key == K_I)
		fractol->max_iter += 10;
	else if (key == K_K && fractol->max_iter)
		fractol->max_iter -= 1;
	else if (key == K_C)
		fractol->updatec *= -1;
	else if (key == K_R || key == K_G || key == K_B || \
			key == K_M || key == K_P || key == K_L || key == K_J)
		colorevent(fractol, key);
	return (0);
}

void	translate_event(t_fractol *fractol, int key)
{
	if (key == K_W)
		translate_view(fractol, 0, DTP);
	else if (key == K_A)
		translate_view(fractol, -DTP, 0);
	else if (key == K_S)
		translate_view(fractol, 0, -DTP);
	else
		translate_view(fractol, DTP, 0);
}

static void	center(t_fractol *fractol, int x, int y)
{
	int	center;
	int	dx;
	int	dy;

	center = DEFAULT_WINDOW_SIZE / 2;
	dx = center - x;
	dy = center - y;
	translate_view(fractol, -dx, dy);
}

int	mouse_event(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == M_SCROLL_UP)
		zoom(fractol, 1);
	else if (button == M_SCROLL_DOWN)
		zoom(fractol, 0);
	else if (button == M_LEFT)
		center(fractol, x, y);
	update_dp(fractol);
	return (0);
}

void	reset(t_fractol *fractol)
{
	fractol->max_iter = DEFAULT_ITER_MAX;
	set_fractal(fractol, fractol->fractal_id);
	update_dp(fractol);
}
