/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:57:12 by yohanafi          #+#    #+#             */
/*   Updated: 2024/02/05 16:09:20 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

typedef struct s_data {
	
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

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
	int		color = 0xABCDEF;
	
	if (pixels_bits != 32)
		color = mlx_get_color_value(mlx, color);
	/*	
	for (int y = 0; y < 1080; ++y)
	for (int x = 0; x < 1920; ++x)
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
	}*/
	printf("Base Color: %X\n", color);
	for (int y = 0; y < 1080; ++y)
	{
	    for (int x = 0; x < 1920; ++x)
	    {
	        int pixel = (y * line_bytes) + (x * 4);
	
	        // Calculer la composante rouge en fonction de la position x
	        int red = (x * 255) / 1920;
			printf("Red: %d\n", red);
	        if (endian == 1)        // Most significant (Alpha) byte first
	        {
	            buffer[pixel + 0] = red;       // Rouge
	            buffer[pixel + 1] = (char)255;       // Vert
	            buffer[pixel + 2] = 0;         // Bleu
	            buffer[pixel + 3] = (char)255;       // Alpha
	        }
	        else if (endian == 0)   // Least significant (Blue) byte first
	        {
	            buffer[pixel + 0] = 0;         // Bleu
	            buffer[pixel + 1] = (char)255;       // Vert
	            buffer[pixel + 2] = red;       // Rouge
	            buffer[pixel + 3] = (char)255;       // Alpha
	        }
	    }
	}

	mlx_put_image_to_window(mlx, mlx_win, image, 0, 0);
	mlx_loop(mlx);
}
