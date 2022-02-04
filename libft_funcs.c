/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_funcs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 20:41:35 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/04 15:12:58 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

#include <unistd.h> /* write */

static unsigned int	ft_strlen(const char *str)
{
	const char	*orig_str;

	orig_str = str;
	while (*str)
	{
		str++;
	}
	return (str - orig_str);
}

/* writes str and a newline to fd. */
void	ft_puts_fd(const int fd, const char *str)
{
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
}

/* prints str with a new line to stdout. */
void	ft_puts(const char *str)
{
	ft_puts_fd(1, str);
}

/* prints str with a new line to stdout. */
void	ft_write_str(const int fd, const char *str)
{
	write(fd, str, ft_strlen(str));
}
