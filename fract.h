/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fract.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 17:04:56 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/01/31 17:30:21 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

typedef struct	s_mlx_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx_data;

typedef struct	s_mlx_vars
{
	void		*mlx;
	void		*win;
	t_mlx_data	*img;
}				t_mlx_vars;

#endif
