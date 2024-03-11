/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:54:21 by yohanafi          #+#    #+#             */
/*   Updated: 2024/03/11 11:37:53 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "mlx/mlx.h"

# define MALLOC_ERROR 1
# define WIDTH 1000
# define HEIGHT 1000

// KEY_EVENT 

// Define RGB colors from HEX
# define BLACK           0x000000
# define WHITE           0xFFFFFF
# define RED             0xFF0000
# define GREEN           0x00FF00
# define BLUE            0x0000FF
# define YELLOW          0xFFFF00
# define CYAN            0x00FFFF
# define MAGENTA         0xFF00FF
# define GRAY            0x808080
# define PSYCHEDELIC_1   0xF50909   // Red
# define PSYCHEDELIC_2   0x0D98BA   // Turquoise
# define PSYCHEDELIC_3   0x9A0DF5   // Purple
# define PSYCHEDELIC_4   0xFF8B00   // Orange
# define PSYCHEDELIC_5   0x00BFFF   // Deep Sky Blue
# define PSYCHEDELIC_6   0x98FF00   // Chartreuse
# define PSYCHEDELIC_7   0xFF00FF   // Fuchsia
# define PSYCHEDELIC_8   0x00FF00   // Lime
# define PSYCHEDELIC_9   0xFFD700   // Gold
# define PSYCHEDELIC_10  0xFF69B4   // Hot Pink

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_leng;
}				t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_defintion;
	double	zoom;
	double	shift_x;
	double	shift_y;
	double	julia_x;
	double	julia_y;
}					t_fractal;

typedef struct s_params_map
{
	double	unscaled_num;
	double	new_min;
	double	new_max;
	double	old_min;
	double	old_max;
}				t_params_map;

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

/*--------INIT--------*/
void		fractal_init(t_fractal *fractal);
void		data_init(t_fractal *fractal);
void		init_img_clean(t_img *img);
int			key_press(int keycode, t_fractal *fractal);
int			ft_close(t_fractal *fractal);
void		event(t_fractal *fractal);

/*--------RENDER--------*/
int			mouse_handle(int mousecode, int x, int y, t_fractal *fractal);
void		fractal_render(t_fractal *fractal);

/*--------UTILS--------*/
double		ft_map(t_params_map p);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			ft_strncmp(const char *s1, char *s2, size_t n);
void		putstr_fd(char *s, int fd);
double		atodbl(char *s, long integer_part, 
				double pow, double fractional_part);

#endif 