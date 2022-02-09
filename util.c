/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 14:59:42 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/09 18:42:32 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

#include "mlx.h"

#include <stdlib.h> /* exit */

void	put_pixel(t_mlx_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*((unsigned int *)dst) = color;
}

/*double	constrain(const int value, const int min, const int max, \
	const double fmin, const double fmax)
{
	return (fmin + ((((double)value) / (double)(max - min)) * (fmax - fmin)));
}*/
/* returns a double as a proportion of the int between 0 and max,
 * starting at fmin and ending at fmax. i.e. map(1, 2, -1.0f 3.0f)
 * returns 2.0f.
 * this is basically the above function, except min is just 0.
 * this is because of the norm. */
double	ft_dmap(const int value, const int max, \
	const double fmin, const double fmax)
{
	return (fmin + ((((double)value) / (double)(max)) * (fmax - fmin)));
}

/* The first bit of a IEEE 754 64 bit double is the sign. If the sign is 1,
 * that means it's negative. So if we want the absolute value, instead of 
 * doing an if statement(which is a branch and computers do not like branches)
 * simply set the first bit to 0. Bitwise operations do not work with doubles,
 * so first it is "casted" to a unsigned long long, which is 64 bit. Unclear
 * wether this function is actually faster than branching. */
double	ft_dabs(const double f)
{
	unsigned long long	casted;

	casted = *((unsigned long long *)(&f));
	casted &= 0x7fffffffffffffff;
	return (*((double *)(&casted)));
}

void	exit_program(const int code, const t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img->img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(code);
}
