/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:57:36 by dhomem-d          #+#    #+#             */
/*   Updated: 2021/11/12 14:53:44 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	start;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	start = ft_strlen(dst);
	if (dest_len < dstsize - 1 && dstsize > 0)
	{
		while ((start < dstsize - 1) && (*src != '\0'))
		{
			dst[start] = *src;
			start++;
			src++;
		}
		dst[start] = '\0';
	}
	if (dest_len >= dstsize)
		dest_len = dstsize;
	return (dest_len + src_len);
}

// void test(int size)
// {
//     char first[] = "This is ";
//     char last[] = "a potentially long string";
//     int r;
//     char buffer[size];
//     strcpy(buffer,first);
//     r = strlcat(buffer,last,size);
// 	char first2[] = "This is ";
//     char last2[] = "a potentially long string";
//     int r2;
//     char buffer2[size];
//     strcpy(buffer2,first2);
//     r2 = ft_strlcat(buffer2,last2,size);
//     puts(buffer);
//     printf("Value returned: %d\n",r);
//     if( r > size )
//         puts("String truncated");
//     else
//         puts("String was fully copied");
// 	puts(buffer2);
//     printf("Value returned: %d\n",r2);
//     if( r2 > size)
//         puts("String truncated");
//     else
//         puts("String was fully copied");
// }
// int	main()
// {
// 	test(23);
// 	return (0);
// }