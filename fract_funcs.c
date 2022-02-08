/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fract_funcs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 14:53:49 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/08 17:05:27 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static int	brot_inner(t_vars *vars, t_vec2 pos, t_vec2 c)
{
	float	oldx;
	int		i;

	i = 0;
	while (i < MAX_ITER)
	{
		oldx = pos.x;
		pos.x = pos.x * pos.x - pos.y * pos.y;
		pos.y = 2 * oldx * pos.y; // play around with this
		pos.x += c.x;
		pos.y += c.y;
		if (ft_fabs(pos.x + pos.y) > 16)
			break ;
		i++;
	}
	return (i);
}

void	julia_pixel(t_vars *vars, int imgx, int imgy)
{
	t_vec2	pos;

	pos.x = ft_fmap(imgx, WIDTH, vars->graph_start.x, vars->graph_end.x);
	pos.y = ft_fmap(imgy, HEIGHT, vars->graph_start.y, vars->graph_end.y);
	draw_pixel(vars, brot_inner(vars, pos, vars->julia_c), imgx, imgy);
}

void	brot_pixel(t_vars *vars, int imgx, int imgy)
{
	t_vec2	pos;
	t_vec2	c;

	c.x = ft_fmap(imgx, WIDTH, vars->graph_start.x, vars->graph_end.x);
	c.y = ft_fmap(imgy, HEIGHT, vars->graph_start.y, vars->graph_end.y);
	pos.x = 0.0f;
	pos.y = 0.0f;
	draw_pixel(vars, brot_inner(vars, pos, c), imgx, imgy);
}

void	iterate_image(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			(*vars->fract_func)(vars, x, y);
			x++;
		}
		y++;
	}
}
