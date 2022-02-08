/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translation.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 13:50:05 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/08 17:43:39 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	translate(float x, float y, t_vars *vars)
{
	const float	factor = 0.1f;
	t_vec2		delta;

	delta = vec2_calc_delta(vars->graph_start, vars->graph_end);
	vec2_divide_scalar(&delta, 2.0f);
	vars->graph_start.x += x * delta.x * factor;
	vars->graph_end.x += x * delta.x * factor;
	vars->graph_start.y += y * delta.y * factor;
	vars->graph_end.y += y * delta.y * factor;
}

void	calc_zoom(t_vars *vars, int x, int y, const float factor)
{
	t_vec2	delta;
	t_vec2	origin_rel;

	origin_rel.x = ((float)x / (float)WIDTH);
	origin_rel.y = ((float)y / (float)HEIGHT);
	vec2_multiply_scalar(&origin_rel, 2.0f);
	delta = vec2_calc_delta(vars->graph_start, vars->graph_end);
	vec2_divide_scalar(&delta, 2.0f);
	vars->graph_start.x += delta.x * origin_rel.x * factor;
	vars->graph_start.y += delta.y * origin_rel.y * factor;
	vars->graph_end.x -= delta.x * (2.0f - origin_rel.x) * factor;
	vars->graph_end.y -= delta.y * (2.0f - origin_rel.y) * factor;
}

void	reset_zoom(t_vars *vars)
{
	vars->graph_start.x = -1.0f * (float)WIDTH / ((float)DEFAULT_WIDTH / 2.0f);
	vars->graph_start.y = -1.0f * (float)HEIGHT
		/ ((float)DEFAULT_HEIGHT / 2.0f);
	vars->graph_end.x = 1.0f * (float)WIDTH / ((float)DEFAULT_WIDTH / 2.0f);
	vars->graph_end.y = 1.0f * (float)HEIGHT / ((float)DEFAULT_HEIGHT / 2.0f);
}
