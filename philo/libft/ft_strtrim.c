/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:24:38 by dhomem-d          #+#    #+#             */
/*   Updated: 2021/11/15 17:52:41 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_setstart(char *string, char *set)
{
	int	set_counter;
	int	stri_counter;

	set_counter = 0;
	stri_counter = 0;
	while (set[set_counter])
	{
		while (set[set_counter] == string[stri_counter])
		{
			stri_counter++;
			if (set[set_counter] != string[stri_counter])
				set_counter = 0;
		}
		set_counter++;
	}
	return (stri_counter);
}

static int	ft_setend(char *string, char *set)
{
	int	set_counter;
	int	stri_counter;

	set_counter = 0;
	stri_counter = ft_strlen(string) - 1;
	while (set[set_counter])
	{
		while (set[set_counter] == string[stri_counter])
		{
			stri_counter--;
			if (set[set_counter] != string[stri_counter])
				set_counter = 0;
		}
		set_counter++;
	}
	return (stri_counter);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstring;
	int		start;
	int		end;
	int		counter;

	if (!s1 || !set)
		return (NULL);
	counter = 0;
	start = ft_setstart((char *) s1, (char *) set);
	end = ft_setend((char *) s1, (char *) set);
	if (start > end)
		return (ft_strdup(""));
	newstring = (char *) malloc (((end - start) + 2) * sizeof(char));
	if (!newstring)
		return (NULL);
	while (s1[start] && start <= end)
	{
		newstring[counter] = s1[start];
		start++;
		counter++;
	}
	newstring[counter] = '\0';
	return (newstring);
}

// int main()
// {
// 	printf("%s\n", ft_strtrim("abcdba", "abc"));
// 	return 0;
// }