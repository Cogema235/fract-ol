/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:00:10 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/02 19:22:35 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../complex.h"

t_complex	complex(double re, double im)
{
	t_complex	z;

	z.im = im;
	z.re = re;
	return (z);
}

double	modc(t_complex z)
{
	return (sqrt(z.re * z.re + z.im * z.im));
}

void	squarec(t_complex *z)
{
	double	a;
	double	b;

	a = z->re;
	b = z->im;
	z->re = a * a - b * b;
	z->im = 2 * a * b;
}

void	addc(t_complex *z0, t_complex z1)
{
	z0->re += z1.re;
	z0->im += z1.im;
}

void	multcr(t_complex *z, double x)
{
	z->re *= x;
	z->im *= x;
}
