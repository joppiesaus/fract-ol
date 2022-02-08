/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 14:51:19 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/08 14:28:49 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#include "keys.h"

#include <mlx.h>

static int	key_hook_inner(const int keycode, t_vars *vars)
{
	if (keycode == KEYCODE_NUMPAD_ZERO)
		reset_zoom(vars);
	else if (keycode == KEYCODE_NUMPAD_EIGHT)
		vars->julia_c.y += 0.1f;
	else if (keycode == KEYCODE_NUMPAD_TWO)
		vars->julia_c.y -= 0.1f;
	else if (keycode == KEYCODE_NUMPAD_FOUR)
		vars->julia_c.x += 0.1f;
	else if (keycode == KEYCODE_NUMPAD_SIX)
		vars->julia_c.x -= 0.1f;
	else if (keycode == KEYCODE_NUMROW_ONE
		&& vars->color_func != &fract_colorfunc_1)
		vars->color_func = &fract_colorfunc_1;
	else if (keycode == KEYCODE_NUMROW_TWO
		&& vars->color_func != &fract_colorfunc_2)
		vars->color_func = &fract_colorfunc_2;
	else
		return (0);
	return (1);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("%d\n", keycode); // REMOVE
	if (keycode == KEYCODE_ESC)
	{
		exit_program(0, vars);
		return (0);
	}
	else if (keycode == KEYCODE_NUMPAD_PLUS)
		calc_zoom(vars, WIDTH / 2, HEIGHT / 2, 0.1f);
	else if (keycode == KEYCODE_NUMPAD_MINUS)
		calc_zoom(vars, WIDTH / 2, HEIGHT / 2, -0.1f);
	else if (keycode == KEYCODE_ARROWKEY_UP)
		translate(0, -1.0f, vars);
	else if (keycode == KEYCODE_ARROWKEY_DOWN)
		translate(0, 1.0f, vars);
	else if (keycode == KEYCODE_ARROWKEY_LEFT)
		translate(-1.0f, 0, vars);
	else if (keycode == KEYCODE_ARROWKEY_RIGHT)
		translate(1.0f, 0, vars);
	else if (!key_hook_inner(keycode, vars))
		return (0);
	iterate_image(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
	if (mousecode == MOUSECODE_SCROLL_DOWN)
	{
		calc_zoom(vars, x, y, 0.1f);
	}
	else if (mousecode == MOUSECODE_SCROLL_UP)
	{
		calc_zoom(vars, x, y, -0.1f);
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
