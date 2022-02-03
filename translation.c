/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translation.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 13:50:05 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/03 13:50:49 by jobvan-d      ########   odam.nl         */
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

void	calc_zoom(t_vars *vars, const float factor)
{
	t_vec2		delta;

	delta = vec2_calc_delta(vars->graph_start, vars->graph_end);
	vec2_divide_scalar(&delta, 2.0f);
	vars->graph_start.x += delta.x * factor;
	vars->graph_start.y += delta.y * factor;
	vars->graph_end.x -= delta.x * factor;
	vars->graph_end.y -= delta.y * factor;
}

void	reset_zoom(t_vars *vars)
{
	vars->zoom = 1.0f;
	vars->graph_start.x = INITIAL_GRAPH_START_X * vars->zoom;
	vars->graph_start.y = INITIAL_GRAPH_START_Y * vars->zoom;
	vars->graph_end.x = INITIAL_GRAPH_END_X * vars->zoom;
	vars->graph_end.y = INITIAL_GRAPH_END_Y * vars->zoom;
}
