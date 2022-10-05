/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:56:03 by dhomem-d          #+#    #+#             */
/*   Updated: 2021/11/15 13:56:39 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			counter;
	unsigned char	*sing;
	unsigned char	new;

	sing = (unsigned char *)s;
	counter = 0;
	new = c;
	while (counter < n)
	{
		if (sing[counter] == new)
		{
			sing += counter;
			return (sing);
		}
		counter++;
	}
	return (NULL);
}

// int main()
// {
// 	char s[] = {0, 1, 2, 3, 4, 5};
// 	printf("%s", ft_memchr(s, 2 + 256, 3));
// }