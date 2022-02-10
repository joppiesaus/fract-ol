/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 15:15:39 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/02/10 15:15:42 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

#include <pthread.h> /* pthread* */
#include <stdlib.h> /* exit */
#include <stdio.h> /* perror */

static void	*thread_iter_image(void *arg)
{
	t_thread_args	*args;
	int				x;
	int				y;

	args = (t_thread_args *)arg;
	y = args->start / WIDTH;
	x = args->start % WIDTH;
	printf("COOL THREAD: %d\n", args->start);
	while (y * WIDTH + x < args->start + (HEIGHT * WIDTH / NTHREADS))
	{
		(*args->vars->fract_func)(args->vars, x, y);
		x++;
		if (x >= WIDTH)
		{
			x = 0;
			y++;
		}
	}
	printf("COOL THREAD DONE: %d\n", args->start);
	return ((void *)0);
}

static void	create_threads(t_vars *vars, pthread_t *threads,
	t_thread_args *targs)
{
	int	i;

	i = 0;
	while (i < NTHREADS)
	{
		targs[i].vars = vars;
		targs[i].start = i * (HEIGHT * WIDTH / NTHREADS);
		if (pthread_create(&threads[i], NULL,
				&thread_iter_image, &targs[i]) == -1)
		{
			perror("pthread_create");
			exit(1);
		}
		i++;
	}
}

static void	wait_for_threads(pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < NTHREADS)
	{
		if (pthread_join(threads[i], NULL) == -1)
		{
			perror("pthread_join");
			exit(1);
		}
		i++;
	}
}

void	iterate_image(t_vars *vars)
{
	pthread_t		threads[NTHREADS];
	t_thread_args	targs[NTHREADS];

	create_threads(vars, threads, targs);
	wait_for_threads(threads);
}
