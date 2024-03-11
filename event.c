/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:53:54 by yohanafi          #+#    #+#             */
/*   Updated: 2024/03/11 11:36:25 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_fractal *fractal)
{
	(void)fractal;
	exit(0);
}

int	key_press(int keycode, t_fractal *fractal)
{
	if (keycode == 53)
		ft_close(fractal);
	else if (keycode == 126)
		fractal->shift_y += (0.25 * fractal->zoom);
	else if (keycode == 125)
		fractal->shift_y -= (0.25 * fractal->zoom);
	else if (keycode == 123)
		fractal->shift_x -= (0.25 * fractal->zoom);
	else if (keycode == 124)
		fractal->shift_x += (0.25 * fractal->zoom);
	fractal_render(fractal);
	return (0);
}

int	mouse_handle(int mousecode, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
		fractal->zoom *= 1.5;
	if (mousecode == 5)
		fractal->zoom *= 0.5;
	fractal_render(fractal);
	return (0);
}

void	event(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, 2, 0, key_press, fractal);
	mlx_hook(fractal->mlx_window, 17, 0, ft_close, fractal);
	mlx_hook(fractal->mlx_window, 4, 0, mouse_handle, fractal);
}
