/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:57:53 by dhomem-d          #+#    #+#             */
/*   Updated: 2021/11/12 15:17:12 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;

	if (dstsize == 0)
		return (ft_strlen(src));
	counter = 0;
	if (dstsize > 0)
	{
		while ((counter != dstsize - 1) && (src[counter] != '\0'))
		{
			dst[counter] = src[counter];
			counter++;
		}
	}
	dst[counter] = '\0';
	return (ft_strlen(src));
}

// void test(int size)
// {
//     char string[] = "Hello there, Venus";
//     char buffer[19];
//     int r;

// 	char string2[] = "Hello there, Venus";
//     char buffer2[19];
//     int r2;

//     r = strlcpy(buffer,string,size);
// 	r2 = ft_strlcpy(buffer2,string,size);
//     printf("Copied '%s' into '%s', length %d\n",
//             string,
//             buffer,
//             r
//           );

// 	printf("Copied '%s' into '%s', length %d\n",
//             string2,
//             buffer2,
//             r2
//           );
// }

// int main()
// {
//     test(19);
//     test(10);
//     test(1);
//     test(0);

//     return(0);
// }