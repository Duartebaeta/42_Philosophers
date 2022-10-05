/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:04:14 by dhomem-d          #+#    #+#             */
/*   Updated: 2021/11/12 16:37:54 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*pointer;

	pointer = malloc(count * size);
	if (!(pointer))
		return (0);
	ft_bzero(pointer, count * size);
	return (pointer);
}

// int main()
// {
// 	char *test;
// 	test = (char *) ft_calloc (1, sizeof(char *));
// 	return 0;
// }