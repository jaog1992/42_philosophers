/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:15:54 by jde-orma          #+#    #+#             */
/*   Updated: 2024/01/24 17:15:54 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include "../libraries/libft/include/libft.h"

# define PHILO_MAX 200
# define TRUE 1
# define FALSE 0
// EXIT_SUCCESS	0
// EXIT_FAILURE	1

// The structure of each philosopher
typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

// The Witness structure 
typedef struct s_program
{
	int				dead_flag;
	t_philo			*philos;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
}					t_program;

// Initialization
void	init_program(t_program *program, t_philo *philos);
void	init_forks(pthread_mutex_t *forks, int philos_num);
void	init_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks, char **argv);
void	init_input(t_philo *philos, char **argv);

// Threads
int		dead_loop(t_philo *philo);
void	*philo_routine(void *pointer);
int		thread_create(t_program *program, pthread_mutex_t *forks);
void	destroy_mutex(char *str, t_program *program, pthread_mutex_t *forks);

// Actions
void	think(t_philo *philo);
void	dream(t_philo *philo);
void	eat(t_philo *philo);

// Monitor
void	*monitor_routine(void *pointer);
int		no_more_meals_flag(t_philo *philos);
int		dead_flag(t_philo *philos);
int		philosopher_dead(t_philo *philo, size_t time_to_die);
void	print_message(char *str, t_philo *philo, int id);

#endif