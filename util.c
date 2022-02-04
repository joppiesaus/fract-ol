/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 14:59:42 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/04 14:58:16 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

#include "mlx.h"

void	put_pixel(t_mlx_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*((unsigned int *)dst) = color;
}

float	constrain(const int value, const int min, const int max, \
	const float fmin, const float fmax)
{
	return (fmin + ((((float)value) / (float)(max - min)) * (fmax - fmin)));
}

/* The first bit of a IEEE 32 bit float is the sign. If the sign is 1,
 * that means it's negative. So if we want the absolute value, instead of 
 * doing an if statement(which is a branch and computers do not like branches)
 * simply set the first bit to 0. Bitwsise operations do not work with floats,
 * so first it is "casted" to a unsigned int. Unclear wether this function is
 * actually faster than branching. */
float	ft_fabs(const float f)
{
	unsigned int	casted;

	casted = *((unsigned int *)(&f));
	casted &= 0x7fffffff;
	return (*((float *)(&casted)));
}

void	exit_program(const int code, const t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img->img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(code);
}
