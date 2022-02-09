/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translation.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 13:50:05 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/09 18:35:29 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	translate(double x, double y, t_vars *vars)
{
	const double	factor = 0.1;
	t_vec2			delta;

	delta = vec2_calc_delta(vars->graph_start, vars->graph_end);
	vec2_divide_scalar(&delta, 2.0);
	vars->graph_start.x += x * delta.x * factor;
	vars->graph_end.x += x * delta.x * factor;
	vars->graph_start.y += y * delta.y * factor;
	vars->graph_end.y += y * delta.y * factor;
}

void	calc_zoom(t_vars *vars, int x, int y, const double factor)
{
	t_vec2	delta;
	t_vec2	origin_rel;

	origin_rel.x = ((double)x / (double)WIDTH);
	origin_rel.y = ((double)y / (double)HEIGHT);
	vec2_multiply_scalar(&origin_rel, 2.0);
	delta = vec2_calc_delta(vars->graph_start, vars->graph_end);
	vec2_divide_scalar(&delta, 2.0);
	vars->graph_start.x += delta.x * origin_rel.x * factor;
	vars->graph_start.y += delta.y * origin_rel.y * factor;
	vars->graph_end.x -= delta.x * (2.0 - origin_rel.x) * factor;
	vars->graph_end.y -= delta.y * (2.0 - origin_rel.y) * factor;
}

void	reset_zoom(t_vars *vars)
{
	vars->graph_start.x = -1.0 * (double)WIDTH / ((double)DEFAULT_WIDTH / 2.0);
	vars->graph_start.y = -1.0 * (double)HEIGHT
		/ ((double)DEFAULT_HEIGHT / 2.0);
	vars->graph_end.x = 1.0 * (double)WIDTH / ((double)DEFAULT_WIDTH / 2.0);
	vars->graph_end.y = 1.0 * (double)HEIGHT / ((double)DEFAULT_HEIGHT / 2.0);
}
