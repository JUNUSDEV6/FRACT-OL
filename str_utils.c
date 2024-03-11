/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:39:09 by yohanafi          #+#    #+#             */
/*   Updated: 2024/03/11 11:40:46 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_atodbl(void)
{
	putstr_fd("error value julia plz enter only digit between (-2 to 2)\n", 2);
	exit(1);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

double	atodbl(char *s, long integer_part, double pow, double fractional_part)
{
	int		sign;
	double	result;

	sign = +1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
		sign *= 1 - (2 * (*s++ == '-'));
	while (ft_isdigit(*s))
		integer_part = (integer_part * 10) + (*s++ - 48);
	if (*s == '.')
		++s;
	while (ft_isdigit(*s))
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	if (*s)
		error_atodbl();
	result = (integer_part + fractional_part) * sign;
	if (result < -2.0 || result > 2.0)
		error_atodbl();
	return (result);
}

int	ft_strncmp(const char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}
