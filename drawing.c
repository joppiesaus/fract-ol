/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 14:20:43 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/10 14:08:59 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

unsigned int	ft_floor(double i)
{
	return ((unsigned int)i);
}

unsigned char	lininterp_byte(unsigned char a, unsigned char b, double i)
{
	return (a + ft_floor((double)(b - a) * i));
}

unsigned int	col_linear_interp(unsigned int a, unsigned int b, double i)
{
	unsigned int	color;

	color = 0;
	color = lininterp_byte(a & 0xff, b & 0xff, i);
	a >>= 8;
	b >>= 8;
	color += lininterp_byte(a & 0xff, b & 0xff, i) << 8;
	a >>= 8;
	b >>= 8;
	color += lininterp_byte(a & 0xff, b & 0xff, i) << 16;
	return (color);
}

int	fract_colorfunc_1(const int i)
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
	else
		color = (unsigned int)(((double)i / (double)MAX_ITER)
				* (double)0xffffff);
	return (color);
}

int	fract_colorfunc_2(const int i)
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

void	draw_pixel(t_vars *vars, int i, int x, int y)
{
	unsigned int	color;

	if (i == MAX_ITER)
		color = 0;
	else
		color = (*vars->color_func)(i);
	put_pixel(vars->img, x, y, color);
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
