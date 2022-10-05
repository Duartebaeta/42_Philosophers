/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:38:10 by dhomem-d          #+#    #+#             */
/*   Updated: 2021/11/03 15:46:36 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	len;

	len = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_putnbr(int nb, char *string, int len)
{
	unsigned int	test;

	if (nb < 0)
		len -= 1;
	test = nb;
	if (nb < 0)
	{
		*string = '-';
		test *= -1;
		string++;
	}
	string += len;
	while (test > 9)
	{
		*string = test % 10 + '0';
		test /= 10;
		string--;
	}
	*string = test + '0';
	string--;
}

char	*ft_itoa(int n)
{
	int		len;
	char	*string;

	len = get_len(n) - 1;
	string = (char *) malloc((len + 2) * sizeof(char));
	if (!(string))
		return (NULL);
	string[len + 1] = '\0';
	ft_putnbr(n, string, len);
	return (string);
}

// int main()
// {
// 	printf("%s\n", ft_itoa(-2147483648));
// 	return 0;
// }
