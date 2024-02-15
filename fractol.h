/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:54:21 by yohanafi          #+#    #+#             */
/*   Updated: 2024/02/15 17:14:03 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

#define MALLOC_ERROR 1
#define WIDTH 400
#define HEIGHT 400

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
void 	fractal_init(t_fractal *fractal);

/*--------RENDER--------*/
void	handle_pixels(int x, int y, t_fractal *fractal);
/*--------UTILS--------*/
double	ft_map(t_params_map *p);
int		ft_strncmp(char *s1, char *s2, int n);
void	putstr_fd(char *s, int fd);

#endif 