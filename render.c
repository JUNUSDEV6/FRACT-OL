/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:09:45 by yohanafi          #+#    #+#             */
/*   Updated: 2024/02/15 17:13:55 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	get_struct(t_params_map **params, int value, int side_window, char c)
{
	*params = malloc(sizeof(t_params_map));
	if (!*params)
	{
		free (*params);
		return ;
	}
	(*params)->unscaled_num = value;
	(*params)->old_max = side_window;
	(*params)->old_min = 0;
	if (c == 'x')
	{
		(*params)->new_min = -2;
		(*params)->new_max = +2;
	}
	else if (c == 'y')
	{
		(*params)->new_min = +2;
		(*params)->new_max = -2;
	}
}

void	handle_pixels(int x, int y, t_fractal *fractal)
{
	t_complex		z;
	t_complex		c;
	t_params_map	*params_x;
	t_params_map	*params_y;

	get_struct(&params_x, x, WIDTH, 'x');
	get_struct(&params_y, y, HEIGHT, 'y');
	z.x = 0.0;
	z.y = 0.0;
	c.x = ft_map(params_x);
	c.y = ft_map(params_y);
}

