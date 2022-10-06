/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:55:16 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/10/06 18:52:31 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_rules	*rules;

	if (arg_checker(argc, argv))
	{
		printf("Argument error\n");
		return (2);
	}
	rules = (t_rules *)malloc(sizeof(t_rules));
	if (!rules)
		return (3);
	if (init_all(argv, rules))
		return (4);
	simulator(rules);
	free_vars(rules);
	return (0);
}

int	arg_checker(int argc, char **argv)
{
	int	counter;
	int	subcounter;

	if (argc != 5 && argc != 6)
		return (1);
	counter = 1;
	while (argv[counter])
	{
		subcounter = 0;
		while (argv[counter][subcounter])
		{
			if (ft_isdigit(argv[counter][subcounter]))
				subcounter++;
			else
				return (2);
		}
		counter++;
	}
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) < 0
		|| ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (3);
	return (0);
}

void	free_vars(t_rules *rules)
{
	free(rules->forks);
	free(rules->forks_bool);
	free(rules->threads);
	free(rules->philos);
	free(rules);
}
