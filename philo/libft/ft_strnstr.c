/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:58:21 by dhomem-d          #+#    #+#             */
/*   Updated: 2021/11/15 16:05:56 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*too_manylines(const char *haystack, size_t counter, size_t match)
{
	haystack += counter - match + 1;
	return ((char *)haystack);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	counter;
	size_t	match;
	size_t	size;

	size = ft_strlen(needle);
	counter = 0;
	match = 0;
	if (size == 0)
		return ((char *)haystack);
	while (haystack[counter] != '\0' && counter < len)
	{
		if (haystack[counter] == needle[match])
			match++;
		else
		{
			counter -= match;
			match = 0;
		}
		if (match == size)
			return (too_manylines(haystack, counter, match));
		counter++;
	}
	return (NULL);
}

// int main()
// {
// 	// char haystack[30] = "aaabcabcd";
// 	// char needle[10] = "aabc";
// 	char * empty = (char*)"";

// 	printf("FT = %s\n", ft_strnstr(empty, "", -1));
// 	printf("OR = %s\n", strnstr(empty, "", -1));
// 	return (0);
// }