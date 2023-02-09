/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:05:07 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/02 19:17:01 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	render_hline(t_fractol *fractol, int i0, int j, int l)
{
	t_complex	current_point;
	int			iter0;
	int			iter;
	int			i;
	int			ok;

	ok = 1;
	current_point.re = fractol->left_down_lim.re + i0 * fractol->dp;
	current_point.im = fractol->righ_top_lim.im - j * fractol->dp;
	iter0 = fractol->convergence(fractol, current_point);
	set_pixel(&fractol->render, i0, j, fractol->iter2color(fractol, iter0));
	i = i0;
	i0 += --l;
	current_point.re += fractol->dp;
	while (++i < i0)
	{
		iter = fractol->convergence(fractol, current_point);
		if (ok && iter != iter0)
			ok = 0;
		set_pixel(&fractol->render, i, j, fractol->iter2color(fractol, iter));
		current_point.re += fractol->dp;
	}
	if (!ok)
		return (-1);
	return (iter0);
}

int	render_vline(t_fractol *fractol, int i, int j0, int l)
{
	t_complex	current_point;
	int			iter0;
	int			iter;
	int			j;
	int			ok;

	ok = 1;
	current_point.re = fractol->left_down_lim.re + i * fractol->dp;
	current_point.im = fractol->righ_top_lim.im - j0 * fractol->dp;
	iter0 = fractol->convergence(fractol, current_point);
	set_pixel(&fractol->render, i, j0, fractol->iter2color(fractol, iter0));
	j = j0;
	j0 += --l;
	current_point.im -= fractol->dp;
	while (++j < j0)
	{
		iter = fractol->convergence(fractol, current_point);
		if (ok && iter != iter0)
			ok = 0;
		set_pixel(&fractol->render, i, j, fractol->iter2color(fractol, iter));
		current_point.im -= fractol->dp;
	}
	if (!ok)
		return (-1);
	return (iter0);
}
