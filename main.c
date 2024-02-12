/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:57:12 by yohanafi          #+#    #+#             */
/*   Updated: 2024/02/07 14:28:30 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int	main(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	//mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	system("leaks fractol");
}

/*
typedef struct s_data {
	
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx = mlx_init();
	void	*mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello Word!");;
	void	*image = mlx_new_image(mlx, 1920, 1080);
	int		pixels_bits;
	int		line_bytes;
	int		endian;
	char	*buffer = mlx_get_data_addr(image, &pixels_bits, &line_bytes, &endian);
	int		color = 0xefcdab;
	
	line_bytes /= 4;
	if (pixels_bits != 32)
		color = mlx_get_color_value(mlx, color);
	for(int y = 0; y < 1920; ++y)
	for(int x = 0; x < 1080; ++x)
	{
    	buffer[(y * line_bytes) + x] = color;
	}
	for (int y = 0; y < 1080; ++y)
	for(int x = 0; x < 1920; ++x)
	{
    	int pixel = (y * line_bytes) + (x * 4);

    	if (endian == 1)        // Most significant (Alpha) byte first
    	{
    	    buffer[pixel + 0] = (color >> 24);
    	    buffer[pixel + 1] = (color >> 16) & 0xFF;
    	    buffer[pixel + 2] = (color >> 8) & 0xFF;
    	    buffer[pixel + 3] = (color) & 0xFF;
    	}
    	else if (endian == 0)   // Least significant (Blue) byte first
    	{
    	    buffer[pixel + 0] = (color) & 0xFF;
    	    buffer[pixel + 1] = (color >> 8) & 0xFF;
    	    buffer[pixel + 2] = (color >> 16) & 0xFF;
    	    buffer[pixel + 3] = (color >> 24);
    	}
	}
	mlx_put_image_to_window(mlx, mlx_win, image, 0, 0);
	mlx_loop(mlx);
	free(mlx);
}*/
