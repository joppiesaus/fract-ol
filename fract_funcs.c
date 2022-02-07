/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fract_funcs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 14:53:49 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/07 18:46:46 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static int	m_colorfunc_1(const int i)
{
	int	color;

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
		color = (unsigned int)(((float)i / (float)MAX_ITER)
				* (float)0xffffff);
	return (color);
}

static int	m_colorfunc_2(const int i)
{
	const int	colors[16] = {
		0x421e0f,
		0x19071a,
		0x09012f,
		0x040449,
		0x000764,
		0x0c2c8a,
		0x1852b1,
		0x397dd1,
		0x86b5e5,
		0xd3ecf8,
		0xf1e9bf,
		0xf8c95f,
		0xffaa00,
		0xcc8000,
		0x995700,
		0x693403
	};

	return (colors[i & 0xf]);
}

// TODO; colofrucn var selection
static void	draw_pixel(t_vars *vars, int i, int x, int y)
{
	unsigned int	color;

	if (i == MAX_ITER)
		color = 0;
	else
		color = m_colorfunc_1(i);
	put_pixel(vars->img, x, y, color);
}

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
