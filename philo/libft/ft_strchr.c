/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:57:21 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/07/25 17:27:09 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		if (s[counter] == (char)c)
		{
			s += counter;
			return ((char *)s);
		}
		counter++;
	}
	if (s[counter] == (char) c)
	{
		s += counter;
		return ((char *)s);
	}
	return (NULL);
}

// int	main()
// {
// 	printf("%s", ft_strchr("ola Tudo bem", '\0'));
// 	return (0);
// }