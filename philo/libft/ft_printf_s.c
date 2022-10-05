/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:44:45 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/01/27 14:21:48 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_s(char *data)
{
	int	counter;

	if (data == NULL)
	{
		counter = ft_printf("(null)");
		return (counter);
	}
	counter = 0;
	ft_putstr_fd(data, 1);
	while (data[counter] != '\0')
		counter++;
	return (counter);
}
