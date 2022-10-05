/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:08:48 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/10/05 23:00:40 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_time(t_rules *rules)
{
	struct timeval	tv;
	long long		sec;
	long long		usec;

	gettimeofday(&tv, NULL);
	sec = tv.tv_sec - rules->start_time.tv_sec;
	usec = tv.tv_usec - rules->start_time.tv_usec;
	return ((usec / 1000) + (sec * 1000));
}

long long	time_since_last(t_rules *rules, t_philo *philo)
{
	if (philo->meals_had != 0)
		return (get_time(rules) - philo->last_meal);
	return (get_time(rules));
}

long long	time_until_death(t_rules *rules, t_philo *philo)
{
	long long	temp = time_since_last(rules, philo);
	if (temp > rules->time_die)
		return (0);
	return (rules->time_die - temp);
}

int	is_dying(t_rules *rules, t_philo *philo, int fork)
{
	if (!rules->forks_bool[fork])
		return (EXIT_SUCCESS);
	if (time_since_last(rules, philo) + rules->time_eat > rules->time_die)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	release_forks(t_rules *rules, t_philo *philo)
{
	pthread_mutex_unlock(&rules->forks[philo->left_fork_id]);
	pthread_mutex_unlock(&rules->forks[philo->right_fork_id]);
	rules->forks_bool[philo->left_fork_id] = 0;
	rules->forks_bool[philo->right_fork_id] = 0;
}