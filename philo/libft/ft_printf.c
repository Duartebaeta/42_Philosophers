/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:39:37 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/01/27 14:22:04 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_selector(char param, va_list args)
{
	if (param == 'c')
		return (ft_printf_c(va_arg(args, int)));
	else if (param == 's')
		return (ft_printf_s(va_arg(args, char *)));
	else if (param == 'p')
	{
		ft_putstr_fd("0x", 1);
		return (ft_printf_p(va_arg(args, unsigned long)));
	}
	else if (param == 'd')
		return (ft_printf_di(va_arg(args, int)));
	else if (param == 'i')
		return (ft_printf_di(va_arg(args, int)));
	else if (param == 'u')
		return (ft_printf_u(va_arg(args, unsigned int)));
	else if (param == 'x')
		return (ft_printf_x(va_arg(args, unsigned int), 0));
	else if (param == 'X')
		return (ft_printf_x(va_arg(args, unsigned int), 1));
	else if (param == '%')
		return (ft_printf_c('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;
	int		total;

	va_start(args, format);
	counter = 0;
	total = 0;
	while (format[counter] != '\0')
	{
		if (format[counter] == '%')
		{
			if (ft_strchr("cspdiuxX%", format[counter + 1]) != NULL)
			{
				total += ft_selector(format[counter + 1], args);
				counter += 2;
			}
		}
		else
			total += needsomelines(format[counter++]);
	}
	va_end(args);
	return (total);
}

// int main()
// {
// 	int total;
// 	total = ft_printf(" %c %c %c ", '0', 0, '1');
// 	printf("\nMy total=%i\n", total);
// 	total = printf(" %c %c %c ", '0', 0, '1');
// 	printf("\nTrue total=%i\n", total);
// 	return 0;
// }
