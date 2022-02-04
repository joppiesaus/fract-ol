/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 15:27:17 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/04 13:52:45 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static void	skip_whitespace(char **str)
{
	while (**str == ' ' || (**str >= '\t' && **str <= '\r'))
	{
		(*str)++;
	}
}

static float	atof_postdecimal(const char *str)
{
	float		result;
	float		divisor;

	result = 0.0f;
	divisor = 1.0f;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10.0f;
		divisor *= 10.0f;
		result += (float)(*str - '0');
		str++;
	}
	result /= divisor;
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
		result += atof_postdecimal(str + 1);
	if (is_negative)
		result = -result;
	return (result);
}

int	is_valid_float_format(char *str)
{
	char	*str_before_numberskip;
	int		number_before_dot;

	skip_whitespace(&str);
	if (*str == '-' || *str == '+')
		str++;
	str_before_numberskip = str;
	while (*str >= '0' && *str <= '9')
		str++;
	number_before_dot = str_before_numberskip < str;
	if (*str == 0 && number_before_dot)
		return (1);
	if (*str != '.')
		return (0);
	str++;
	str_before_numberskip = str;
	while (*str >= '0' && *str <= '9')
		str++;
	if (str_before_numberskip == str && !number_before_dot)
		return (0);
	skip_whitespace(&str);
	return (*str == 0);
}