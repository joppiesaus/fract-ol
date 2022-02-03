/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_funcs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 20:41:35 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/03 20:41:57 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

#include <unistd.h> /* write */

static unsigned int	ft_strlen(const char *str)
{
	const char *orig_str;

	orig_str = str;
	while (*str)
	{
		str++;
	}
	return (str - orig_str);
}

void	ft_puts(const char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}
