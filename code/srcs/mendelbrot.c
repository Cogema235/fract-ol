/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:00:23 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/01 16:03:18 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mendelbrot.h"

unsigned int	divmendel(t_complex z, unsigned int max_iter)
{
	return (divjulia(z, z, max_iter));
}
