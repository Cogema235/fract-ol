/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:52:25 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/06 18:04:01 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

t_event	event(int event, int mask, int (*funct)(), void *param)
{
	t_event	event_;

	event_.event = event;
	event_.mask = mask;
	event_.funct = funct;
	event_.param = param;
	return (event_);
}
