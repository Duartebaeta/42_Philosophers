/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:12:22 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/10/06 22:46:55 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	printer(t_rules *rules, t_philo *philo, char *message)
{
	pthread_mutex_lock(&rules->death_lock);
	if (rules->is_dead)
	{
		pthread_mutex_unlock(&rules->death_lock);
		return (EXIT_FAILURE);
	}
	printf("%lld %d %s\n", get_time(rules), philo->id + 1, message);
	pthread_mutex_unlock(&rules->death_lock);
	return (EXIT_SUCCESS);
}

int	check_meals(t_rules *rules, t_philo *philo)
{
	if (philo->meals_had == rules->n_meals && rules->is_dead == 0)
		rules->meals_done++;
	if (rules->meals_done == rules->n_philo)
	{
		rules->is_dead += 1;
		printf("%lld All Philosophers have eaten enough meals!\n", \
		get_time(rules));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
