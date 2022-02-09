/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec2.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 15:44:45 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/09 18:30:50 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_vec2	vec2_calc_delta(const t_vec2 a, const t_vec2 b)
{
	t_vec2	delta;

	delta.x = b.x - a.x;
	delta.y = b.y - a.y;
	return (delta);
}

void	vec2_divide_scalar(t_vec2 *ref, const double divisor)
{
	ref->x /= divisor;
	ref->y /= divisor;
}

void	vec2_multiply_scalar(t_vec2 *ref, const double multiplier)
{
	ref->x *= multiplier;
	ref->y *= multiplier;
}
