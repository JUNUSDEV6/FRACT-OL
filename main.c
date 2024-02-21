/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:57:12 by yohanafi          #+#    #+#             */
/*   Updated: 2024/02/20 12:55:05 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))||
	(argc == 4 && !ft_strncmp(argv[2], "julia", 5)))
	{
		fractal.name = argv[1];
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
		putstr_fd("ERROR INPUT\n", 2);
		exit(1);	
}

/*
int	main(void)
{
	t_fractol	z;
	t_fractol	c;
	double		tmp_real;

	z.real = 0;
	z.i = 0; 

	c.real = 5;
	c.i = 2;
	for (int i = 0; i < 42; ++i)
	{
		tmp_real = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z.real * z.i;
		z.real = tmp_real;
		z.real += c.real;
		z.i += c.i;
		printf("iterration m -> %d real %f imaginary %f\n", i, z.real, z.i);
	}
}*/
