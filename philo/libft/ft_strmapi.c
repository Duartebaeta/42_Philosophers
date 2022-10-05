/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:17:32 by dhomem-d          #+#    #+#             */
/*   Updated: 2021/11/12 14:54:12 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		counter;
	char	*newstring;

	counter = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	newstring = (char *) malloc ((counter + 1) * sizeof(char));
	if (!(newstring))
		return (NULL);
	counter = 0;
	while (s[counter] != '\0')
	{
		newstring[counter] = f(counter, s[counter]);
		counter++;
	}
	newstring[counter] = '\0';
	return (newstring);
}
