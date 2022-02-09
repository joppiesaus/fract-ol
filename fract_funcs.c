/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fract_funcs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 14:53:49 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/09 16:00:38 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	brot_inner(t_vec2 pos, t_vec2 c)
{
	float	oldx;
	int		i;

	i = 0;
	while (i < MAX_ITER)
	{
		oldx = pos.x;
		pos.x = pos.x * pos.x - pos.y * pos.y;
		pos.y = 2 * oldx * pos.y;
		pos.x += c.x;
		pos.y += c.y;
		if (ft_fabs(pos.x + pos.y) > 16)
			break ;
		i++;
	}
	return (i);
}

/* basically this is the mandelbrot fractal, except
 * calculated with absolute values. */
int	burning_ship_inner(t_vec2 pos, t_vec2 c)
{
	float	oldx;
	int		i;
	t_vec2	pos_sq;

	i = 0;
	while (i < MAX_ITER)
	{
		pos_sq = pos;
		pos_sq.x *= pos_sq.x;
		pos_sq.y *= pos_sq.y;
		if (pos_sq.x + pos_sq.y > 2 * 2)
			break ;
		oldx = pos.x;
		pos.x = pos_sq.x - pos_sq.y + c.x;
		pos.y = ft_fabs(2 * oldx * pos.y) + c.y;
		i++;
	}
	return (i);
}

void	julia_pixel(t_vars *vars, int imgx, int imgy)
{
	t_vec2	pos;

	pos.x = ft_fmap(imgx, WIDTH, vars->graph_start.x, vars->graph_end.x);
	pos.y = ft_fmap(imgy, HEIGHT, vars->graph_start.y, vars->graph_end.y);
	draw_pixel(vars, (*vars->inner_fract_func)(pos, vars->julia_c), imgx, imgy);
}

void	brot_pixel(t_vars *vars, int imgx, int imgy)
{
	t_vec2	pos;
	t_vec2	c;

	c.x = ft_fmap(imgx, WIDTH, vars->graph_start.x, vars->graph_end.x);
	c.y = ft_fmap(imgy, HEIGHT, vars->graph_start.y, vars->graph_end.y);
	pos.x = 0.0f;
	pos.y = 0.0f;
	draw_pixel(vars, (*vars->inner_fract_func)(pos, c), imgx, imgy);
}
