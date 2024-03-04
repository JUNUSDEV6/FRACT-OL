/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:53:54 by yohanafi          #+#    #+#             */
/*   Updated: 2024/03/04 11:12:46 by yohanafi         ###   ########.fr       */
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
	return (0);
}

void	event(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, 2, 0, key_press, fractal);
	mlx_hook(fractal->mlx_window, 17, 0, ft_close, fractal);
	//mlx_mouse_hook(fractal->mlx_window, mouse_event, fractal);
}