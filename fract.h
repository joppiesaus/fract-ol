/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fract.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 17:04:56 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/04 13:32:07 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# define WIDTH (800)
# define HEIGHT (800)
# define MAX_ITER (100)

# define INITIAL_GRAPH_START_X (-2.0f)
# define INITIAL_GRAPH_END_X (2.0f)
# define INITIAL_GRAPH_START_Y (-2.0f)
# define INITIAL_GRAPH_END_Y (2.0f)
/*# define INITIAL_GRAPH_START_X (-01.42f)
# define INITIAL_GRAPH_END_X (1.0f)
# define INITIAL_GRAPH_START_Y (-1.12f)
# define INITIAL_GRAPH_END_Y (1.12f)*/



typedef struct	s_mlx_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx_data;

typedef struct	s_vec2
{
	float	x;
	float	y;
}				t_vec2;

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	t_mlx_data	*img;
	t_vec2		graph_start;
	t_vec2		graph_end;
	t_vec2		julia_c;
	float		zoom;
	void		(*fract_func)(struct s_vars *, int, int);
}				t_vars;

void	exit_program(const int code, const t_vars *vars);
void	put_pixel(t_mlx_data *data, int x, int y, unsigned int color);
float	constrain(const int value, const int min, const int max, \
					const float fmin, const float fmax);
float	ft_fabs(const float f);

void	calc_zoom(t_vars *vars, const float factor);
void	translate(float x, float y, t_vars *vars);
void	reset_zoom(t_vars *vars);

t_vec2	vec2_calc_delta(const t_vec2 a, const t_vec2 b);
void	vec2_divide_scalar(t_vec2 *ref, const float divisor);

float	ft_atof(const char *str);
void	ft_puts(const char *str);
int		is_valid_float_format(const char *str);


#endif
