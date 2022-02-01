/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 17:05:50 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/01 13:14:08 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

#include <mlx.h>

void	exit_program(const int code, const t_mlx_vars *vars)
{
	//mlx_destroy_image(vars->img->img, )
	mlx_destroy_window(vars->mlx, vars->win);
	exit(code);
}

int	key_hook(int keycode, t_mlx_vars *vars)
{
	//printf("%d\n", keycode);
	if (keycode == 53)
	{
		exit_program(0, vars);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx_vars	vars;
	t_mlx_data	data;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1024, 1024, "jeff");
	data.img = mlx_new_image(vars.mlx, 1024, 1024);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
		&data.line_length, &data.endian);
	//vars.img = &data;
	
	unsigned int	*d = (unsigned int *)data.addr;
	for (unsigned int i = 0; i < 1024 * 1024; i++)
	{
		d[i] = i;
		d[i] <<= 4;
		if (i % 2 == 0)
			d[i] = ~d[i];
		d[i] &= 0x00ffffff;
	}
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, data.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
