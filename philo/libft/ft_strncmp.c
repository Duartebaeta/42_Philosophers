/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:58:09 by dhomem-d          #+#    #+#             */
/*   Updated: 2021/11/15 14:06:47 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			counter;
	unsigned char	*newstr1;
	unsigned char	*newstr2;

	if (n <= 0)
		return (0);
	newstr1 = (unsigned char *) s1;
	newstr2 = (unsigned char *) s2;
	counter = 0;
	while ((newstr1[counter] != '\0' || newstr2[counter] != '\0')
		&& counter < n - 1)
	{
		if (newstr1[counter] == newstr2[counter])
			counter++;
		else
			return (newstr1[counter] - newstr2[counter]);
	}
	if (newstr1[counter] == newstr2[counter])
		return (0);
	else
		return (newstr1[counter] - newstr2[counter]);
}

// int main()
// {
// 	printf("Ft = %d\n", ft_strncmp("t", "", 0));
// 	printf("Or = %d\n", strncmp("t", "", 0));
// }
