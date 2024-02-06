/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:06:03 by yohanafi          #+#    #+#             */
/*   Updated: 2024/02/06 14:47:25 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"
#include <mlx.h>

typedef struct s_mx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx_data;

int	handle_intput(int keysym, t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
	
}

int	main(void)
{
	
}