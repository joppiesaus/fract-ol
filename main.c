/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 17:05:50 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/04 13:32:46 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#include "keys.h"

#include <mlx.h>

#include <stdio.h> // remove

void	iterate_image(t_vars *vars);

int	key_hook(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if (keycode == KEYCODE_ESC)
	{
		exit_program(0, vars);
		return (0);
	}
	else if (keycode == KEYCODE_NUMPAD_PLUS)
		calc_zoom(vars, 0.1f);
	else if (keycode == KEYCODE_NUMPAD_MINUS)
		calc_zoom(vars, -0.1f);
	else if (keycode == KEYCODE_ARROWKEY_UP)
		translate(0, -1.0f, vars);
	else if (keycode == KEYCODE_ARROWKEY_DOWN)
		translate(0, 1.0f, vars);
	else if (keycode == KEYCODE_ARROWKEY_LEFT)
		translate(-1.0f, 0, vars);
	else if (keycode == KEYCODE_ARROWKEY_RIGHT)
		translate(1.0f, 0, vars);
	else if (keycode == KEYCODE_NUMPAD_ZERO)
		reset_zoom(vars);
	else if (keycode == KEYCODE_NUMPAD_EIGHT)
		vars->julia_c.y += 0.1f;
	else if (keycode == KEYCODE_NUMPAD_TWO)
		vars->julia_c.y -= 0.1f;
	else if (keycode == KEYCODE_NUMPAD_FOUR)
		vars->julia_c.x += 0.1f;
	else if (keycode == KEYCODE_NUMPAD_SIX)
		vars->julia_c.x -= 0.1f;
	else
	{
		return (0);
	}
	iterate_image(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
	if (mousecode == 4)
	{
		calc_zoom(vars, 0.1f);
	}
	else if (mousecode == 5)
	{
		calc_zoom(vars, -0.1f);
	}
	else
	{
		return (0);
	}
	iterate_image(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}

/* called when the window is closed by user */
int	destroy_hook(t_vars	*vars)
{
	exit_program(0, vars);
	return (0);
}

void	draw_pixel(t_vars *vars, int i, int x, int y)
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
	//process_colors(data, iterarr);
}


void	display_valid_args()
{
	ft_puts("m - displays mandelbrot");
	ft_puts("j <a> <b> - displays julia set");
}

int	parse_args(t_vars *vars, int argc, char **argv)
{
	const char *fract_type;

	if (argc < 2)
		return (0);
	fract_type = argv[1];
	if (*fract_type == 'm' && fract_type[1] == 0)
	{
		vars->fract_func = &brot_pixel;
		return (1);
	}
	else if (*fract_type == 'j' && fract_type[1] == 0)
	{
		if (argc < 4 || !is_valid_float_format(argv[2])
			|| !is_valid_float_format(argv[2]))
			return (0);
		vars->julia_c.x = ft_atof(argv[2]);
		vars->julia_c.y = ft_atof(argv[3]);
		vars->fract_func = &julia_pixel;
		return (1);
	}
	return (0);
}

int	init_mlx()
{

}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_mlx_data	data;

	if (!parse_args(&vars, argc, argv))
	{
		display_valid_args();
		return (0);
	}
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (1);
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fract-ol");
	data.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
		&data.line_length, &data.endian);
	vars.img = &data;
	reset_zoom(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 17, 0L, destroy_hook, &vars);
	iterate_image(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img->img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
