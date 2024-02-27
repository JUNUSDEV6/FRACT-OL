/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:44:03 by yohanafi          #+#    #+#             */
/*   Updated: 2024/02/27 09:59:53 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_img_clean(t_img *img)
{
	img->img_ptr = NULL;
	img->pixels_ptr = NULL;
	img->bpp = 0;
	img->line_leng = 0;
	img->endian = 0;
}

static void	malloc_error(void)
{
	printf("ERROR MALLOC");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_defintion = 42;
}

// static void	event_init(t_fractal *fractal)
// {
// 	//mlx_hook(fractal->mlx_connection, KeyPress, KeyPressMask, key_handle, fractal);
// }

 // The keycode for the ESC key (you can adjust this if needed)

// static int key_event(int keycode, void *param)
// {
//     (void)param;  // Suppress unused parameter warning

//     // Print the keycode using printf
//     printf("Key pressed: %d\n", keycode);

//     // You can perform other actions or call other functions based on the keyboard event.

//     return 0;  // Return 0 to indicate that the event has been handled
// }

int key_event(t_fractal *fractal, int keycode)
{
    (void)fractal;  // Suppress unused parameter warning
	if (keycode == KEY_ESCAPE)
		exit(EXIT_FAILURE);
    // Close button clicked, close the window and quit the program
    //printf("Close button clicked. Exiting...\n");
	return (0);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, 
			WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		malloc_error();
	}
	//mlx_hook(fractal->mlx_window, 2, 0, key_event, NULL);
	//mlx_key_hook(fractal->mlx_window, key_event, NULL);
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, 
			WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, 
			&fractal->img.bpp, &fractal->img.line_leng, &fractal->img.endian);
	//event_init();
	mlx_key_hook(fractal->mlx_window, key_event, NULL);
	data_init(fractal);
}
