/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:19:17 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/10/05 21:25:40 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_all(char **argv, t_rules *rules)
{
	rules->is_dead = 0;
	rules->n_philo = ft_atoi(argv[1]);
	rules->time_die = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	rules->meals_done = 0;
	gettimeofday(&rules->start_time, NULL);
	rules->forks_bool = (int *)ft_calloc(rules->n_philo, sizeof(int));
	if (argv[5])
		rules->n_meals = ft_atoi(argv[5]);
	else
		rules->n_meals = -1;
	if (rules->n_philo < 1 || rules->time_die < 0 || rules->time_eat < 0
		|| rules->time_sleep < 0)
		return (1);
	if (init_aloc(rules))
		return (3);
	if (init_mut(rules))
		return (2);
	init_philo(rules);
	return (0);
}

int	init_philo(t_rules *rules)
{
	int	i;

	i = rules->n_philo;
	while (--i >= 0)
	{
		rules->philos[i].id = i;
		if (rules->philos[i].id % 2)
		{
			rules->philos[i].left_fork_id = rules->philos[i].id;
			rules->philos[i].right_fork_id = (rules->philos[i].id + 1)
				% rules->n_philo;
		}
		else
		{
			rules->philos[i].left_fork_id = (rules->philos[i].id + 1)
				% rules->n_philo;
			rules->philos[i].right_fork_id = rules->philos[i].id;
		}
		rules->philos[i].meals_had = 0;
		rules->philos[i].last_meal = 0;
	}
	return (0);
}

int	init_mut(t_rules *rules)
{
	int	i;

	i = rules->n_philo;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(rules->death_lock), NULL))
		return (1);
	if (pthread_mutex_init(&(rules->increment_lock), NULL))
		return (1);
	if (pthread_mutex_init(&(rules->meal_lock), NULL))
		return (1);
	return (0);
}

int	init_aloc(t_rules *rules)
{
	rules->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* rules->n_philo);
	if (!rules->forks)
		return (1);
	rules->philos = (t_philo *)malloc(sizeof(t_philo) * rules->n_philo);
	if (!rules->philos)
		return (2);
	rules->threads = (pthread_t *)malloc(sizeof(pthread_t) * rules->n_philo);
	if (!rules->threads)
		return (3);
	return (0);
}
