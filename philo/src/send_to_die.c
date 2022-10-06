/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_die.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:44:31 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/10/06 22:47:32 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	send_to_die(t_rules *rules, t_philo *philo, long long sleep)
{
	usleep(sleep * 1000);
	pthread_mutex_lock(&rules->death_lock);
	if (rules->is_dead)
	{
		pthread_mutex_unlock(&rules->death_lock);
		return ;
	}
	rules->is_dead += 1;
	printf("%lld %d %s\n", get_time(rules), philo->id + 1, "is dead");
	pthread_mutex_unlock(&rules->death_lock);
}
