/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:07:12 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/06 19:21:19 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	translate_view(t_fractol *fractol, int dx, int dy)
{
	double	cdx;
	double	cdy;

	cdx = dx * fractol->dp;
	cdy = dy * fractol->dp;
	fractol->righ_top_lim.im += cdy;
	fractol->righ_top_lim.re += cdx;
	fractol->left_down_lim.im += cdy;
	fractol->left_down_lim.re += cdx;
}

void	zoom(t_fractol *fractol, int factor)
{
	double	cdx;
	double	cdy;

	cdx = DTP * fractol->dp;
	cdy = DTP * fractol->dp;
	if (factor)
	{
		fractol->righ_top_lim.im -= cdy;
		fractol->righ_top_lim.re -= cdx;
		fractol->left_down_lim.im += cdy;
		fractol->left_down_lim.re += cdx;
	}
	else
	{
		fractol->righ_top_lim.im += cdy;
		fractol->righ_top_lim.re += cdx;
		fractol->left_down_lim.im -= cdy;
		fractol->left_down_lim.re -= cdx;
	}
}
