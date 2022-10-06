/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:30:36 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/10/06 22:47:41 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*start_simulation(void *r)
{
	t_rules		*rules;
	t_philo		*philo;
	static int	counter = 0;

	rules = (t_rules *) r;
	pthread_mutex_lock(&(rules->increment_lock));
	philo = &rules->philos[counter++];
	if (philo->id % 2 == 0)
		usleep(5 * 1000);
	pthread_mutex_unlock(&(rules->increment_lock));
	while (1 && rules->n_meals != 0)
	{
		if (take_forks(rules, philo))
			break ;
		if (start_eating(rules, philo))
			break ;
		if (start_sleeping(rules, philo))
			break ;
	}
	return (EXIT_SUCCESS);
}

void	init_threads(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_philo)
	{
		pthread_create(&(rules->threads[i]), NULL,
			start_simulation, (void *)rules);
		i++;
	}
}

void	join_threads(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_philo)
	{
		pthread_join(rules->threads[i], NULL);
		i++;
	}
}

void	destroy_threads(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_philo)
	{
		pthread_mutex_destroy(&rules->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&rules->death_lock);
	pthread_mutex_destroy(&rules->increment_lock);
}

int	simulator(t_rules *rules)
{
	rules->simulation_start = get_time(rules);
	init_threads(rules);
	join_threads(rules);
	destroy_threads(rules);
	return (EXIT_SUCCESS);
}
