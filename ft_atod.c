/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atod.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 15:27:17 by jobvan-d      #+#    #+#                 */
<<<<<<< HEAD:ft_atod.c
/*   Updated: 2022/02/12 13:58:19 by jobvan-d      ########   odam.nl         */
=======
/*   Updated: 2022/02/04 13:51:30 by jobvan-d      ########   odam.nl         */
>>>>>>> 98c6b1525ae11c6d37cffaed5a5a845533a37046:ft_atof.c
/*                                                                            */
/* ************************************************************************** */

static void	skip_whitespace(char **str)
{
	while (**str == ' ' || (**str >= '\t' && **str <= '\r'))
	{
		(*str)++;
	}
}

<<<<<<< HEAD:ft_atod.c
static double	atod_postdecimal(const char *str)
{
	double		result;
	double		divisor;

	result = 0.0;
	divisor = 1.0;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10.0;
		divisor *= 10.0;
		result += (double)(*str - '0');
=======
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
>>>>>>> 98c6b1525ae11c6d37cffaed5a5a845533a37046:ft_atof.c
		str++;
	}
	result /= divisor;
	return (result);
}

double	ft_atod(const char *str)
{
	double	result;
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
	result = 0.0;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10.0;
		result += (double)(*str - '0');
		str++;
	}
	if (*str == '.')
		result += atod_postdecimal(str + 1);
	if (is_negative)
		result = -result;
	return (result);
}

<<<<<<< HEAD:ft_atod.c
int	is_valid_double_format(char *str)
=======
int	is_valid_float_format(char *str)
>>>>>>> 98c6b1525ae11c6d37cffaed5a5a845533a37046:ft_atof.c
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
