/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:57:00 by dhomem-d          #+#    #+#             */
/*   Updated: 2021/11/12 14:46:45 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*newdst;
	char	*newsrc;

	if (dst == NULL && src == NULL)
		return (dst);
	newdst = (char *)dst;
	newsrc = (char *)src;
	while (n != 0)
	{
		*newdst = *newsrc;
		newsrc++;
		newdst++;
		n--;
	}
	return (dst);
}

// int main () {
//    const char str[50] = "foo-bar";
//    char dst[50];
//    strcpy(dst,"Heloooo!!");
//    printf("Before memcpy dst = %s\n", str);
//    ft_memcpy(NULL, NULL, 4);
//    printf("After memcpy dst = %s\n", str);
//    return(0);
// }