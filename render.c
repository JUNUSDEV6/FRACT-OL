/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:09:45 by yohanafi          #+#    #+#             */
/*   Updated: 2024/02/19 15:30:20 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
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
*/
t_params_map	*get_struct(int value, int side_window, char c)
{
	t_params_map	*params;

	params = malloc(sizeof(t_params_map));
    if (!params)
        return (NULL);
    params->unscaled_num = value;
    params->old_max = side_window;
    params->old_min = 0;
    if (c == 'x')
    {
        params->new_min = -2;
        params->new_max = 2;
    }
    else if (c == 'y')
    {
        params->new_min = 2;
        params->new_max = -2;
    }
    return (params);
}

void	handle_pixels(int x, int y, t_fractal *fractal)
{
	t_complex		z;
	t_complex		c;
	int				i;
	int				color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = ft_map(get_struct(x, WIDTH, 'x'));
	c.y = ft_map(get_struct(y, HEIGHT, 'y'));
	while (i < fractal->iterations_defintion)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = ft_map(get_struct(i, fractal->iterations_defintion, 'c'));
			my_pixel_put();
			return ;
		}
	}
}

