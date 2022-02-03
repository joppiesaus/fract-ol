/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atof.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 15:27:17 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/03 16:33:04 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(const int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static void	skip_whitespace(char **str)
{
	while (ft_isspace(**str))
	{
		(*str)++;
	}
}

static float	atof_postdecimal(const char *str)
{
	float		result;
	const char	*orig_str;

	result = 0.0f;
	orig_str = str;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10.0f;
		result += (float)(*str - '0');
		str++;
	}
	result /= (float)(str - orig_str);
	return (result);
}

float	ft_atof(const char *str)
{
	float	result;
	int		is_negative;

	skip_whitespace((char **)&str);
	is_negative = 0;
	if (*str == '-')
	{
		is_negative = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	result = 0.0f;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10.0f;
		result += (float)(*str - '0');
		str++;
	}
	if (*str == '.')
		result += atof_postdecimal(str);
	if (is_negative)
		result = -result;
	return (result);
}
