/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:01:11 by yohanafi          #+#    #+#             */
/*   Updated: 2024/02/15 14:28:48 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_map(t_params_map *p)
{
	return ((p->new_max - p->new_min) * (p->unscaled_num - p->old_min) 
		/ (p->old_max - p->old_min) + p->new_min);
}
