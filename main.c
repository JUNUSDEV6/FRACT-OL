/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:57:12 by yohanafi          #+#    #+#             */
/*   Updated: 2024/03/08 13:16:52 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) 
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
			if (!ft_strncmp(argv[1], "jullia", 5))
			{
				fractal.julia_x = atodbl(argv[2]);
				fractal.julia_y = atodbl(argv[3]);
			}
		fractal_init(&fractal);
		fractal_render(&fractal);
		event(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		putstr_fd("ERROR INPUT\n", 2);
		exit(1);
	}
}
