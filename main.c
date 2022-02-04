/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 17:05:50 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/04 14:59:23 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

#include <mlx.h>

#include <stdio.h> // remove

int	parse_args(t_vars *vars, int argc, char **argv)
{
	const char	*fract_type;

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

static void	display_valid_args(void)
{
	ft_puts("m - displays mandelbrot");
	ft_puts("j <a> <b> - displays julia set");
}

static void	init_mlx(t_vars	*vars, t_mlx_data *img)
{
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "fract-ol");
	img->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	vars->img = img;
	reset_zoom(vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_hook(vars->win, 17, 0L, destroy_hook, vars);
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
	{
		ft_puts_fd(2, "mlx init failed");
		return (1);
	}
	init_mlx(&vars, &data);
	iterate_image(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, data.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
