/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fract_funcs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 14:53:49 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/03/24 13:52:30 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	brot_inner(t_vec2 pos, t_vec2 c, const int max_iter)
{
	double	oldx;
	int		i;

	i = 0;
	while (i < max_iter)
	{
		oldx = pos.x;
		pos.x = pos.x * pos.x - pos.y * pos.y;
		pos.y = 2 * oldx * pos.y;
		pos.x += c.x;
		pos.y += c.y;
		if (ft_dabs(pos.x + pos.y) > 16)
			break ;
		i++;
	}
	return (i);
}

/* basically this is the mandelbrot fractal, except
 * calculated with absolute values. */
int	burning_ship_inner(t_vec2 pos, t_vec2 c, const int max_iter)
{
	double	oldx;
	int		i;
	t_vec2	pos_sq;

	i = 0;
	while (i < max_iter)
	{
		pos_sq = pos;
		pos_sq.x *= pos_sq.x;
		pos_sq.y *= pos_sq.y;
		if (pos_sq.x + pos_sq.y > 2 * 2)
			break ;
		oldx = pos.x;
		pos.x = pos_sq.x - pos_sq.y + c.x;
		pos.y = ft_dabs(2 * oldx * pos.y) + c.y;
		i++;
	}
	return (i);
}

void	julia_pixel(t_vars *vars, int imgx, int imgy)
{
	t_vec2	pos;

	pos.x = ft_dmap(imgx, WIDTH, vars->graph_start.x, vars->graph_end.x);
	pos.y = ft_dmap(imgy, HEIGHT, vars->graph_start.y, vars->graph_end.y);
	draw_pixel(vars,
		(*vars->inner_fract_func)(pos, vars->julia_c, vars->max_iter),
		imgx, imgy);
}

void	brot_pixel(t_vars *vars, int imgx, int imgy)
{
	t_vec2	pos;
	t_vec2	c;

	c.x = ft_dmap(imgx, WIDTH, vars->graph_start.x, vars->graph_end.x);
	c.y = ft_dmap(imgy, HEIGHT, vars->graph_start.y, vars->graph_end.y);
	pos.x = 0.0;
	pos.y = 0.0;
	draw_pixel(vars, (*vars->inner_fract_func)(pos, c, vars->max_iter),
		imgx, imgy);
}
