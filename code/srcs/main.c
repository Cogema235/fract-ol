/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:50:02 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/01 16:03:23 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include "../libft/libft.h"

static uint8_t	juliargok(char **av)
{
	return (ft_isnumber(av[2]) && ft_isnumber(av[3]));
}

static void	help(void)
{
	ft_putstr_fd("Arguments incorrects.\n\n"
		"Utilisation : [fract-ol] [Mandelbrot / Julia]\n"
		"              [fract-ol] [julia] [Re(C)] [Im(C)]\n", 1);
	exit(0);
}

static void	julia(char **av, t_fractol *fractol)
{
	double	re;
	double	im;

	if (!juliargok(av))
		help();
	re = ft_atof(av[2]);
	im = ft_atof(av[3]);
	init_fractol(fractol, 1, complex(re, im), -1);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac == 1)
		help();
	else if (ac == 2)
	{
		if (!ft_strcmp(av[1], "Mandelbrot"))
			init_fractol(&fractol, 0, complex(0, 0), -1);
		else if (!ft_strcmp(av[1], "Julia"))
			init_fractol(&fractol, 1, complex(0, 0), 1);
		else
			help();
	}
	else if (ac == 4)
		julia(av, &fractol);
	else
		help();
	return (0);
}
