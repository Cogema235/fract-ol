/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:37:39 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/06 15:21:45 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	update_dp(t_fractol *fractol)
{
	fractol->dp = fabs(fractol->left_down_lim.re \
		- fractol->righ_top_lim.re) / fractol->render.size;
	fractol->csize = fractol->dp * (double)fractol->render.size;
}

int	update_render(t_fractol *fractol)
{
	if (fractol->csize < 4)
		render_square(fractol, 0, 0, fractol->render.size);
	else
		render_square_force(fractol, 0, 0, fractol->render.size);
	put_image(&fractol->render);
	if (fractol->updatec > 0 && fractol->fractal_id == 1)
		updatec(fractol);
	return (0);
}

void	updatec(t_fractol *fractol)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(fractol->render.mlx, fractol->render.win, &x, &y);
	fractol->c.re = -2 + fractol->dp * x;
	fractol->c.im = 2 - fractol->dp * y;
}
