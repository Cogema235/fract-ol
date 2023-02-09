/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sugar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:07:24 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/02 19:13:23 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	set_update(t_render *render, int (*funct_ptr)(), void *context)
{
	mlx_loop_hook(render->mlx, funct_ptr, context);
}

void	start_loop(t_render *render)
{
	mlx_loop(render->mlx);
}

void	put_image(t_render *render)
{
	mlx_put_image_to_window(render->mlx, render->win, render->image.addr, 0, 0);
}

void	define_event(t_render *render, t_event event)
{
	mlx_hook(render->win, event.event, event.mask, event.funct, event.param);
}

void	init_render(t_render *render, int size, char *title)
{
	render->size = size;
	render->title = title;
	render->mlx = mlx_init();
	render->win = mlx_new_window(render->mlx, size, size, title);
	render->image.addr = mlx_new_image(render->mlx, size, size);
	render->image.buffer = mlx_get_data_addr(render->image.addr, \
		&(render->image.pixels_bits), &(render->image.line_bytes), \
		&(render->image.endian));
}
