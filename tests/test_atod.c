/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_atod.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 16:25:37 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/12 13:54:27 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

double	ft_atod(const char *str);
int	is_valid_double_format(const char *str);

void	test(const char *s, int line)
{
	double	a,b;

	a = atof(s);
	b = ft_atod(s);

	printf("%d: %s: %f, %f\t", is_valid_double_format(s), s, a, b);
	if (a == b)
	{
		printf("good!\n");
	}
	else
	{
		printf("FAIL @ line %d\n", line);
	}
}

#define COMP(s) (test(s, __LINE__))

int	main()
{
	COMP("\t\v\r    +-.2949");
	COMP("\t\v\r    -.2949");
	COMP("\t\v\r    +.2949");
	COMP("\t\v\r1.000090f");
	COMP("\t\v\r1.000090    \t");	
	COMP("1.");
	COMP(".1");
	COMP("");
	COMP("    \v\t");
	COMP("    \v\t.");
	COMP(".0");
	COMP("0.0");
	COMP("1.0");
	COMP("+1");
	COMP("100.0");
	COMP("1.24");
	COMP("1.1");
	COMP("1.14025");
	COMP("-23451.9095");
	COMP("100.101");
	COMP("-100.101");
	COMP("a-100.101");
	COMP("a-100.b101");
	COMP("-100.b101");
	COMP("-10b30.101");
	COMP("-1030....101");
	COMP("\t\v\r    -1428.2481");
	COMP("-1999428.248451");

	return (0);
}