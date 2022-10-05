/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:02:47 by dhomem-d          #+#    #+#             */
/*   Updated: 2021/11/12 14:53:11 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*newstring;
	int		counter;
	int		size;
	char	*str_copy;

	size = ft_strlen(s1);
	newstring = (char *)malloc((size + 1) * sizeof(char));
	if (!(newstring))
		return (0);
	counter = 0;
	str_copy = newstring;
	while (counter < size)
	{
		str_copy[counter] = s1[counter];
		counter++;
	}
	str_copy[counter] = '\0';
	return (newstring);
}

// int main()
// {
//     char source[] = "GeeksForGeeks";

//     // A copy of source is created dynamically
//     // and pointer to copy is returned.
//     char* target = strdup(source);

//     printf("%s\n", target);
// 	printf("%d", ft_strlen(target));
//     return (0);
// }