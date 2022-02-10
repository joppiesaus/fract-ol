/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fract.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 17:04:56 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/10 15:17:02 by jobvan-d      ########   odam.nl         */
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
/* ./fractol jb 0 0.3 is really cool. After all, math is just making stuff up
 * and seeing what happens. */

# define NTHREADS (4)

# define WIDTH (800)
# define HEIGHT (800)
# define MAX_ITER (400)

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
	double	x;
	double	y;
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
	int			(*inner_fract_func)(t_vec2, t_vec2);
}				t_vars;

typedef struct s_thread_args
{
	t_vars	*vars;
	int		start;
}				t_thread_args;

void	exit_program(const int code, const t_vars *vars);
void	put_pixel(t_mlx_data *data, int x, int y, unsigned int color);
double	ft_dmap(const int value, const int max, \
	const double fmin, const double fmax);
double	ft_dabs(const double f);

void	calc_zoom(t_vars *vars, int x, int y, const double factor);
void	translate(double x, double y, t_vars *vars);
void	reset_zoom(t_vars *vars);

t_vec2	vec2_calc_delta(const t_vec2 a, const t_vec2 b);
void	vec2_divide_scalar(t_vec2 *ref, const double divisor);
void	vec2_multiply_scalar(t_vec2 *ref, const double multiplier);

double	ft_atod(const char *str);
int		is_valid_double_format(const char *str);

void	ft_puts_fd(const int fd, const char *str);
void	ft_puts(const char *str);
void	ft_write_str(const int fd, const char *str);

int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int mousecode, int x, int y, t_vars *vars);
int		destroy_hook(t_vars	*vars);

void	brot_pixel(t_vars *vars, int imgx, int imgy);
void	julia_pixel(t_vars *vars, int imgx, int imgy);
int		brot_inner(t_vec2 pos, t_vec2 c);
int		burning_ship_inner(t_vec2 pos, t_vec2 c);

int		fract_colorfunc_1(const int i);
int		fract_colorfunc_2(const int i);
void	draw_pixel(t_vars *vars, int i, int x, int y);
void	iterate_image(t_vars *vars);

#endif
