/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fract_funcs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 14:53:49 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/04 14:55:14 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	draw_pixel(t_vars *vars, int i, int x, int y)
{
	unsigned int color;

	color = 0x00ffffff;
	//printf("%d\n", i);
	if (i == 0)
		color = 0;
	else if (i == 1)
		color = 0x00ff0000;
	else if (i == 2)
		color = 0x00ff8800;
	else if (i == 3)
		color = 0x0011ff00;
	else if (i == 4)
		color = 0x00ff00ff;
	else if (i == MAX_ITER)
		color = 0;
	else
		color = (unsigned int)(((float)i / (float)MAX_ITER) * (float)0x00ffffff);
		//color = constrain(i, 0, MAX_ITER, 0, 0xffffff);
	put_pixel(vars->img, x, y, color);
}


void	julia_pixel(t_vars *vars, int imgx, int imgy)
{
	float	x0;
	float	y0;
	float	x;
	float	y;
	int		i;
	
	x0 = constrain(imgx, 0, WIDTH, vars->graph_start.x, vars->graph_end.x);
	y0 = constrain(imgy, 0, HEIGHT, vars->graph_start.y, vars->graph_end.y);
	x = x0;
	y = y0;
	i = 0;
	float oldx;
	while (i < MAX_ITER)
	{
		oldx = x;
		x = x * x - y * y;
		y = 2 * oldx * y; // play around with this

		x += vars->julia_c.x;
		y += vars->julia_c.y;

		if (ft_fabs(x + y) > 16)
			break ;
		i++;
	}
	draw_pixel(vars, i, imgx, imgy);
}

void	brot_pixel(t_vars *vars, int imgx, int imgy)
{
	float	x0;
	float	y0;
	float	x;
	float	y;
	int		i;
	
	x0 = constrain(imgx, 0, WIDTH, vars->graph_start.x, vars->graph_end.x);
	y0 = constrain(imgy, 0, HEIGHT, vars->graph_start.y, vars->graph_end.y);
	x = 0.0f;
	y = 0.0f;
	i = 0;
	float oldx;
	while (i < MAX_ITER)
	{
		oldx = x;
		x = x * x - y * y;
		y = 2 * oldx * y; // play around with this

		x += x0;
		y += y0;

		if (ft_fabs(x + y) > 16)
			break ;
		i++;
	}
	draw_pixel(vars, i, imgx, imgy);
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
