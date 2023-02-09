/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:52:25 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/06 18:04:01 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	set_pixel(t_render *render, int i, int j, int color)
{
	char	*dst;
	t_image	*image;

	image = &(render->image);
	dst = image->buffer + (j * image->line_bytes + i * \
		(image->pixels_bits / 8));
	*(unsigned int *)dst = color;
}

void	clear_render(t_render *render, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < render->size)
	{
		j = 0;
		while (j < render->size)
		{
			set_pixel(render, i, j, color);
			j++;
		}
		i++;
	}
}

int	kill_render(t_render *render)
{
	mlx_destroy_image(render->mlx, render->image.addr);
	mlx_destroy_window(render->mlx, render->win);
	mlx_destroy_display(render->mlx);
	free(render->mlx);
	exit(0);
	return (0);
}

void	fill_square(t_render *render, int i0, int j0, int l)
{
	int	j;
	int	i;

	i = i0;
	while (i <= i0 + l)
	{
		j = j0;
		while (j <= j0 + l)
		{
			set_pixel(render, i, j, render->cdc);
			j++;
		}
		i++;
	}
}

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
