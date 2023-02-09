/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:01:35 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/06 18:26:29 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	render_square_outline(t_fractol *fractol, int i0, int j0, int l)
{
	int	iter0;
	int	iter1;
	int	iter2;
	int	iter3;

	iter0 = render_hline(fractol, i0, j0, l);
	iter1 = render_hline(fractol, i0, j0 + l, l);
	iter2 = render_vline(fractol, i0, j0, l);
	iter3 = render_vline(fractol, i0 + l, j0, l);
	if (iter1 == iter0 && iter2 == iter0 && iter3 == iter0 && iter0 != -1)
		return (iter0);
	return (-1);
}

void	render_square(t_fractol *fractol, int i0, int j0, int l)
{
	int	res;
	int	ld;

	res = render_square_outline(fractol, i0, j0, l);
	if (res != -1)
	{
		if (fractol->show_opt > 0)
			fractol->render.cdc = fractol->iter2color(fractol, res);
		else
			fractol->render.cdc = trgb(0, 150, 0, 0);
		fill_square(&fractol->render, i0 + 1, j0 + 1, l - 1);
	}
	else if (l >= MIN_SIMPLIFYING_SIZE)
	{
		ld = l / 2;
		render_square(fractol, i0, j0, ld);
		render_square(fractol, i0 + ld, j0, ld);
		render_square(fractol, i0, j0 + ld, ld);
		render_square(fractol, i0 + ld, j0 + ld, ld);
	}
	else
		render_square_force(fractol, i0 + 1, j0 + 1, l - 1);
}

void	render_square_force(t_fractol *fractol, int i0, int j0, int l)
{
	t_complex	current_point;
	double		im0;
	int			i;
	int			j;

	i = i0;
	j = j0;
	im0 = fractol->righ_top_lim.im - j0 * fractol->dp;
	current_point.re = i0 * fractol->dp + fractol->left_down_lim.re;
	while (i <= i0 + l)
	{
		current_point.im = im0;
		j = j0;
		while (j <= j0 + l)
		{
			set_pixel(&fractol->render, i, j, fractol->iter2color(fractol, \
			fractol->convergence(fractol, current_point)));
			current_point.im -= fractol->dp;
			++j;
		}
		current_point.re += fractol->dp;
		++i;
	}
}
