/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:12:38 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/02 19:13:14 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mendelconv(t_fractol *fractol, t_complex z)
{
	return (divmendel(z, fractol->max_iter));
}

int	juliaconv(t_fractol *fractol, t_complex z)
{
	return (divjulia(z, fractol->c, fractol->max_iter));
}

int	droprgb(t_fractol *fractol, uint32_t iter)
{
	double	e;

	if (iter == fractol->max_iter)
		return (0);
	e = (double)iter / (double)(fractol->max_iter);
	return (trgb(0, e * fractol->color.r, e * fractol->color.g, \
		e * fractol->color.b));
}

int	blackonwhite(t_fractol *fractol, uint32_t iter)
{
	double	e;

	e = (double)iter / (double)(fractol->max_iter);
	e = 255 * (1 - e);
	return (trgb(0, e, e, e));
}

int	lsd(t_fractol *fractol, uint32_t iter)
{
	double	e;

	if (iter == fractol->max_iter)
		return (0);
	e = (double)iter / (double)(fractol->max_iter) * 255;
	return (trgb(0, e * fractol->color.r, e * fractol->color.g, \
		e * fractol->color.b));
}
