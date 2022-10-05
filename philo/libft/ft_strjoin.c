/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:13:07 by dhomem-d          #+#    #+#             */
/*   Updated: 2021/11/15 16:01:33 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	size;
	char			*newstring;
	unsigned int	counter;

	counter = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	newstring = (char *) malloc (size * sizeof(char));
	if (!(newstring))
		return (NULL);
	while (*s1 != '\0')
	{
		newstring[counter] = *s1;
		counter++;
		s1++;
	}
	while (counter < size)
	{
		newstring[counter] = *s2;
		counter++;
		s2++;
	}
	return (newstring);
}

// int main()
// {
// 	char	*string;
// 	string = ft_strjoin("ola", " tudo bem?");
// 	printf("%s\n", string);
// 	free(string);
// 	return 0;
// }
