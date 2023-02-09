/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:02:30 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/01 16:02:45 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdint.h>

typedef struct s_image
{
	void	*addr;
	char	*buffer;
	int		pixels_bits;
	int		line_bytes;
	int		endian;
}	t_image;

typedef struct s_render
{
	t_image	image;
	void	*mlx;
	void	*win;
	char	*title;
	int		size;
	int		cdc;
}	t_render;

typedef struct s_event
{
	void	*param;
	int		event;
	int		mask;
	int		(*funct)();
}	t_event;

t_event	event(int event, int mask, int (*funct)(), void *param);
void	init_render(t_render *render, int size, char *title);
void	set_update(t_render *render, int (*funct_ptr)(), void *context);
void	set_pixel(t_render *render, int i, int j, int color);
void	clear_render(t_render *render, int color);
void	start_loop(t_render *render);
void	put_image(t_render *render);
void	define_event(t_render *render, t_event event);
void	fill_square(t_render *render, int i0, int j0, int l);
int		kill_render(t_render *render);
int		trgb(int t, int r, int g, int b);

#endif
