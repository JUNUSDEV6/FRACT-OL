/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:09:45 by yohanafi          #+#    #+#             */
/*   Updated: 2024/02/14 13:17:35 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	get_struct_x(t_params_map *params, int value, int side_window)
{
	params->unscaled_num = value;
	params->new_min = -2;
	params->new_max = +2;
	params->old_min = 0;
	params->old_max = side_window;
}

static void	get_struct_y(t_params_map *params, int value, int side_window)
{
	params->unscaled_num = value;
	params->new_min = +2;
	params->new_max = -2;
	params->old_min = 0;
	params->old_max = side_window;
}

void	handle_error(int x, int y, t_fractal *fractal)
{
	t_complex		z;
	t_complex		c;
	t_params_map	*params_x;
	t_params_map	*params_y;

	get_struct_x(params_x, x, WIDTH);
	get_struct_y(params_y, y, HEIGHT);
	z.x = 0.0;
	z.y = 0.0;
	c.x = ft_map(params_x);
	c.y = ft_map(params_y);
}

