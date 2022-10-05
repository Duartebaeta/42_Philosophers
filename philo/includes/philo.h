/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:01:06 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/10/05 22:01:52 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

typedef struct s_rules
{
	int				n_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				n_meals;
	int				is_dead;
	int				meals_done;
	struct timeval	start_time;
	long long			simulation_start;
	struct s_philo	*philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	int				*forks_bool;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	increment_lock;
	pthread_mutex_t	meal_lock;
}	t_rules;

typedef struct s_philo
{
	int			id;
	int			meals_had;
	int			left_fork_id;
	int			right_fork_id;
	long		last_meal;
	pthread_t	thread_id;
}	t_philo;


long long	get_time(t_rules *rules);
long long	time_since_last(t_rules *rules, t_philo *philo);
void	send_to_die(t_rules *rules, t_philo *philo, long long sleep);
int	is_dying(t_rules *rules, t_philo *philo, int fork);
long long	time_until_death(t_rules *rules, t_philo *philo);
int	take_forks(t_rules *rules, t_philo *philo);
int	init_all(char **argv, t_rules *rules);
int	init_philo(t_rules *rules);
int	init_mut(t_rules *rules);
int	init_aloc(t_rules *rules);
void	*start_simulation(void *r);
int	init_threads(t_rules *rules);
int	join_threads(t_rules *rules);
int	simulator(t_rules *rules);
int	main(int argc, char **argv);
int	arg_checker(int argc, char **argv);
int	printer(t_rules *rules, t_philo *philo, char *message);
void	release_forks(t_rules *rules, t_philo *philo);
int	start_eating(t_rules *rules, t_philo *philo);
int	start_sleeping(t_rules *rules, t_philo *philo);


#endif