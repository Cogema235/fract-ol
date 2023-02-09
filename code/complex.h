/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:56:06 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/02 19:22:50 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# include <math.h>
# include <stdint.h>

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

t_complex	complex(double re, double im);
double		modc(t_complex z);
void		squarec(t_complex *z);
void		addc(t_complex *z0, t_complex z1);
void		multcr(t_complex *z, double x);

#endif