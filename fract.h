/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fract.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 17:04:56 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/08 17:46:02 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H
/* ======     CONTROLS     ===== 
 * numrow 1-2: change colors
 * arrow keys:	move
 * numpad 0:	reset zoom
 * scroll:		zoom
 * numpad +:	zoom in
 * numpad -:	zoom out
 * escape:		quit

 * following only applicable to the julia set:
 * numpad 4: decrement real component of complex number(x axis)
 * numpad 6: increment real component of complex number(x axis)
 * numpad 2: decrement imaginary component of complex number(y axis)
 * numpad 8: increment imaginary component of complex number(y axis)
 */

# define WIDTH (800)
# define HEIGHT (800)
# define MAX_ITER (100)

# define DEFAULT_WIDTH (800)
# define DEFAULT_HEIGHT (800)

typedef struct s_mlx_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx_data;

typedef struct s_vec2
{
	float	x;
	float	y;
}				t_vec2;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_mlx_data	*img;
	t_vec2		graph_start;
	t_vec2		graph_end;
	t_vec2		julia_c;
	int			(*color_func)(const int);
	void		(*fract_func)(struct s_vars *, int, int);
}				t_vars;

void	exit_program(const int code, const t_vars *vars);
void	put_pixel(t_mlx_data *data, int x, int y, unsigned int color);
float	ft_fmap(const int value, const int max, \
	const float fmin, const float fmax);
float	ft_fabs(const float f);

void	calc_zoom(t_vars *vars, int x, int y, const float factor);
void	translate(float x, float y, t_vars *vars);
void	reset_zoom(t_vars *vars);

t_vec2	vec2_calc_delta(const t_vec2 a, const t_vec2 b);
void	vec2_divide_scalar(t_vec2 *ref, const float divisor);
void	vec2_multiply_scalar(t_vec2 *ref, const float multiplier);

float	ft_atof(const char *str);
int		is_valid_float_format(const char *str);

void	ft_puts_fd(const int fd, const char *str);
void	ft_puts(const char *str);
void	ft_write_str(const int fd, const char *str);

int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int mousecode, int x, int y, t_vars *vars);
int		destroy_hook(t_vars	*vars);

void	iterate_image(t_vars *vars);
void	brot_pixel(t_vars *vars, int imgx, int imgy);
void	julia_pixel(t_vars *vars, int imgx, int imgy);

int		fract_colorfunc_1(const int i);
int		fract_colorfunc_2(const int i);
void	draw_pixel(t_vars *vars, int i, int x, int y);

#endif
