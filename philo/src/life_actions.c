/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:38:48 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/10/06 22:45:21 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_forks(t_rules *rules, t_philo *philo)
{
	while (rules->forks_bool[philo->right_fork_id] == 1
		|| rules->forks_bool[philo->left_fork_id] == 1)
	{
		if (time_since_last(rules, philo) > rules->time_die)
		{
			send_to_die(rules, philo, time_until_death(rules, philo));
			return (EXIT_FAILURE);
		}
	}
	pthread_mutex_lock(&rules->forks[philo->left_fork_id]);
	rules->forks_bool[philo->left_fork_id] = 1;
	if (printer(rules, philo, "has taken a fork"))
	{
		rules->forks_bool[philo->left_fork_id] = 0;
		pthread_mutex_unlock(&rules->forks[philo->left_fork_id]);
		return (EXIT_FAILURE);
	}
	if (take_scnd_fork(rules, philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	take_scnd_fork(t_rules *rules, t_philo *philo)
{
	while (rules->forks_bool[philo->right_fork_id] == 1)
	{
		if (time_since_last(rules, philo) > rules->time_die)
		{
			pthread_mutex_unlock(&rules->forks[philo->left_fork_id]);
			send_to_die(rules, philo, time_until_death(rules, philo));
			return (EXIT_FAILURE);
		}
	}
	pthread_mutex_lock(&rules->forks[philo->right_fork_id]);
	rules->forks_bool[philo->right_fork_id] = 1;
	if (printer(rules, philo, "has taken a fork"))
	{
		release_forks(rules, philo);
		return (EXIT_FAILURE);
	}
	if (time_since_last(rules, philo) > rules->time_die)
	{
		release_forks(rules, philo);
		send_to_die(rules, philo, time_until_death(rules, philo));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	start_eating(t_rules *rules, t_philo *philo)
{
	if (printer(rules, philo, "is eating") == EXIT_FAILURE)
	{
		release_forks(rules, philo);
		return (EXIT_FAILURE);
	}
	if (time_since_last(rules, philo) > rules->time_die
		|| rules->time_eat > rules->time_die)
	{
		release_forks(rules, philo);
		send_to_die(rules, philo, time_until_death(rules, philo));
		return (EXIT_FAILURE);
	}
	philo->meals_had++;
	check_meals(rules, philo);
	philo->last_meal = get_time(rules);
	usleep(rules->time_eat * 1000);
	return (EXIT_SUCCESS);
}

int	start_sleeping(t_rules *rules, t_philo *philo)
{
	if (printer(rules, philo, "is sleeping"))
		return (EXIT_FAILURE);
	release_forks(rules, philo);
	if (time_since_last(rules, philo) + rules->time_sleep > rules->time_die)
	{
		send_to_die(rules, philo, time_until_death(rules, philo));
		return (EXIT_FAILURE);
	}
	usleep(rules->time_sleep * 1000);
	if (printer(rules, philo, "is thinking"))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
