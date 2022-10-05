/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:55:24 by dhomem-d          #+#    #+#             */
/*   Updated: 2021/11/11 16:09:36 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_spaces(const char *string)
{
	int	counter;

	counter = 0;
	while (string[counter] == '\t' || string[counter] == '\n'
		|| string[counter] == '\v' || string[counter] == '\f'
		|| string[counter] == '\r' || string[counter] == ' ')
	{
		counter++;
	}
	return (counter);
}

static int	ft_check(const char *string, int starter)
{
	int	len;

	len = 0;
	if (string[starter] == '-' || string[starter] == '+')
	{
		if (string[starter + 1] >= '0' && string[starter + 1] <= '9')
		{
			len++;
			starter++;
		}
	}
	while ((string[starter] >= '0' && string[starter] <= '9'))
	{
		len++;
		starter++;
	}
	return (len);
}

int	ft_atoi(const char *str)
{
	int	len;
	int	mult;
	int	number;
	int	counter;

	mult = 1;
	number = 0;
	counter = ft_spaces(str);
	len = ft_check(str, counter) + counter;
	if (len == 0)
		return (0);
	if (str[counter] == '-' || str[counter] == '+')
	{
		if (str[counter] == '-')
			mult *= -1;
		counter++;
	}
	while (counter < len)
	{
		number += (str[counter] - 48);
		if (counter + 1 < len)
			number *= 10;
		counter++;
	}
	return (number * mult);
}

// int main () {
//    int val;
//    char str[20];
//    strcpy(str, "+2");
//    val = atoi(str);
// 	int val2;
//    char str2[20];
//    strcpy(str2, "+2");
//    val2 = ft_atoi(str2);
//    printf("OR = String value = %s, Int value = %d\n", str, val);
//    printf("FT = String value = %s, Int value = %d\n", str2, val2);
//    return(0);
// }
