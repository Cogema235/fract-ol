/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:01:25 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/01 16:04:15 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENDELBROT_H
# define MENDELBROT_H

# include "complex.h"
# include "julia.h"
# include <stdint.h>

unsigned int	divmendel(t_complex z, unsigned int max_iter);

#endif