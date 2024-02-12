/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:54:21 by yohanafi          #+#    #+#             */
/*   Updated: 2024/02/07 14:36:43 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>

#define MALLOC_ERROR 1
#define WIDTH 400
#define HEIGHT 400

typedef struct s_fractol
{
	double	real;
	double	i;
}				t_fractol;
