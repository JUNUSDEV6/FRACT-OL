/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:53:54 by yohanafi          #+#    #+#             */
/*   Updated: 2024/03/05 16:15:56 by yohanafi         ###   ########.fr       */
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
	else if (keycode == 126) // arrow_up
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

int	mouse_event (int keycode, t_fractal *fractal)
{
	if (keycode == 5)
		fractal->zoom *= 1.5;
	if (keycode == 4)
		fractal->zoom *= 0.95;
	fractal_render(fractal);
	return (0);
}

void	event(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, 2, 0, key_press, fractal);
	mlx_hook(fractal->mlx_window, 17, 0, ft_close, fractal);
	mlx_mouse_hook(fractal->mlx_window, mouse_event, fractal);
}
