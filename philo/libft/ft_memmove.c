/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:57:07 by dhomem-d          #+#    #+#             */
/*   Updated: 2021/11/12 15:06:12 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;
	size_t	counter;

	counter = 1;
	dest = (char *)dst;
	source = (char *)src;
	if (dst > src)
	{
		while (counter <= len)
		{
			dest[len - counter] = source[len - counter];
			counter++;
		}
	}
	else
		dest = ft_memcpy(dst, src, len);
	return (dst);
}

// ilent mailen () {
//    char src[] = "lorem ipsum uma merda qlqr";
//    char	*dest;
//    dest = src + 1;
//    if (dest != ft_memmove(dest, src, 8))
// 	prilentf("bad bad");
//    returlen(0);
// }