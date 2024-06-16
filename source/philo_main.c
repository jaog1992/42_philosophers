/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:14:15 by jde-orma          #+#    #+#             */
/*   Updated: 2024/01/24 17:14:15 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "../libraries/libft/include/libft.h"

int	ft_string_of_digits(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_argument_check(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (ft_print_error("Invalid argument count. 4 to 5 expected\n"));
	if (ft_string_of_digits(argv[1]) \
		|| ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0)
		return (ft_print_error("Invalid number of philosophers\n"));
	if (ft_string_of_digits(argv[2]) || ft_atoi(argv[2]) <= 0)
		return (ft_print_error("Invalid time to die\n"));
	if (ft_string_of_digits(argv[3]) || ft_atoi(argv[3]) <= 0)
		return (ft_print_error("Invalid time to eat\n"));
	if (ft_string_of_digits(argv[4]) || ft_atoi(argv[4]) <= 0)
		return (ft_print_error("Invalid time to sleep\n"));
	if ((argv[5] && (ft_atoi(argv[5]) < 0)) || ft_string_of_digits(argv[5]))
		return (ft_print_error("Invalid total meal number per philosopher\n"));
	return (EXIT_SUCCESS);
}
// memset, , malloc, free, write,
// usleep, gettimeofday

// pthread_create
// pthread_detach
// pthread_join

// pthread_mutex_init
// pthread_mutex_destroy
// pthread_mutex_lock
// pthread_mutex_unlock

// Number of mutex-s
// Each Philo has a fork (right) and points to the previous fork (left)
// The first philo points to the last philo's fork (as in a circle)
// 		pthread_mutex_t	*r_fork;
// 		pthread_mutex_t	*l_fork;

// Each philos sync their meal, dead and write mutexes to the Witness's
// 		pthread_mutex_t	*write_lock;
// 		pthread_mutex_t	*dead_lock;
// 		pthread_mutex_t	*meal_lock;

// Witness's main routine: monitor_routine
// Each Philo's main routine: philo_routine
// Main program's main routine: main

// Dudas en philo_threads y philo_monitor
int	main(int argc, char **argv)
{
	t_program		program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (init_argument_check(argc, argv))
		return (EXIT_FAILURE);
	init_program(&program, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &program, forks, argv);
	thread_create(&program, forks);
	destroy_mutex(NULL, &program, forks);
	return (EXIT_SUCCESS);
}
