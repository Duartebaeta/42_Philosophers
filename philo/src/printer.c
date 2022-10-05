/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:12:22 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/10/05 22:33:07 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	printer(t_rules *rules, t_philo *philo, char *message)
{
	pthread_mutex_lock(&rules->death_lock);
	if (philo->meals_had == rules->n_meals)
		rules->meals_done++;
	if (rules->is_dead || rules->meals_done == rules->n_philo)
	{
		pthread_mutex_unlock(&rules->death_lock);
		return (EXIT_FAILURE);
	}
	printf("%lld %d %s\n", get_time(rules), philo->id + 1, message);
	pthread_mutex_unlock(&rules->death_lock);
	return (EXIT_SUCCESS);
}