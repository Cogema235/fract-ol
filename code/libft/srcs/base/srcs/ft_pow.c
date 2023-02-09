/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:35:48 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:31:06 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double	ft_pow(double x, unsigned int p)
{
	double	res;

	if (p == 0)
		return (1);
	res = 1;
	while (p)
	{
		res *= x;
		p--;
	}
	return (res);
}
