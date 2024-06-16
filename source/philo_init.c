/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:40:03 by jde-orma          #+#    #+#             */
/*   Updated: 2024/01/25 21:40:03 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "../libraries/libft/include/libft.h"

// Init program structre
void	init_program(t_program *program, t_philo *philos)
{
	program->dead_flag = 0;
	program->philos = philos;
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
}

// Init fork mutexes
void	init_forks(pthread_mutex_t *forks, int philos_num)
{
	int	i;

	i = 0;
	while (i < philos_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

// Init user args
void	init_input(t_philo *philos, char **argv)
{
	philos->time_to_die = ft_atoi(argv[2]);
	philos->time_to_eat = ft_atoi(argv[3]);
	philos->time_to_sleep = ft_atoi(argv[4]);
	philos->num_of_philos = ft_atoi(argv[1]);
	if (argv[5])
		philos->num_times_to_eat = ft_atoi(argv[5]);
	else
		philos->num_times_to_eat = -1;
}

// Init philosophers
void	init_philos(t_philo *philos, t_program *program, \
					pthread_mutex_t *forks, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		init_input(&philos[i], argv);
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].start_time = ft_gettime();
		philos[i].last_meal = ft_gettime();
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].write_lock = &program->write_lock;
		philos[i].dead = &program->dead_flag;
		philos[i].r_fork = &forks[i];
		if (i == 0)
			philos[i].l_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].l_fork = &forks[i - 1];
		i++;
	}
}
