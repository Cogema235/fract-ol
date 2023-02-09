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

static void	incrred(t_fractol *fractol)
{
	static uint8_t	incr = 1;

	if (fractol->color.r == 255)
		incr = -1;
	else if (fractol->color.r == 0)
		incr = 1;
	fractol->color.r += incr;
}

static void	incrgreen(t_fractol *fractol)
{
	static uint8_t	incg = 1;

	if (fractol->color.g == 255)
		incg = -1;
	else if (fractol->color.g == 0)
		incg = 1;
	fractol->color.g += incg;
}

static void	incrblue(t_fractol *fractol)
{
	static uint8_t	incb = 1;

	if (fractol->color.b == 255)
		incb = -1;
	else if (fractol->color.b == 0)
		incb = 1;
	fractol->color.b += incb;
}

void	colorevent(t_fractol *fractol, int key)
{
	if (key == K_R)
		incrred(fractol);
	else if (key == K_G)
		incrgreen(fractol);
	else if (key == K_B)
		incrblue(fractol);
	else if (key == K_L)
		fractol->iter2color = lsd;
	else if (key == K_M)
		fractol->iter2color = blackonwhite;
	else if (key == K_P)
		fractol->iter2color = droprgb;
	else
	{
		fractol->color.r = 0;
		fractol->color.g = 0;
		fractol->color.b = 0;
	}
}
