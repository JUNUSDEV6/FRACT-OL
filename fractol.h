/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:54:21 by yohanafi          #+#    #+#             */
/*   Updated: 2024/02/13 13:20:16 by yohanafi         ###   ########.fr       */
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
	void	
}				t_img;


typedef struct s_fractol
{
	double	real;
	double	i;
}				t_fractol;

// UTILS 
int		ft_strncmp(char *s1, char *s2, int n);
void	putstr_fd(char *s, int fd);

#endif 