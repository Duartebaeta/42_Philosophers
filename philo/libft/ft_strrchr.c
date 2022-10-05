/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:58:29 by dhomem-d          #+#    #+#             */
/*   Updated: 2021/11/15 14:03:26 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				counter;
	int				occcurrence;
	unsigned char	new;

	counter = 0;
	occcurrence = -1;
	new = c;
	while (s[counter] != '\0')
	{
		if (s[counter] == new)
			occcurrence = counter;
		counter++;
	}
	if (s[counter] == new)
		occcurrence = counter;
	if (occcurrence == -1)
		return (NULL);
	s += occcurrence;
	return ((char *)s);
}

// int main()
// {
// 	char s[] = "tripouille";
// 	printf("%s", ft_strrchr(s, 't' + 256));
// 	return (0);
// }