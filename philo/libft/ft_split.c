/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:10:46 by dhomem-d          #+#    #+#             */
/*   Updated: 2021/11/09 15:55:05 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	counter;
	int	word_exists;
	int	words;

	counter = 0;
	words = 0;
	while (s[counter] != '\0')
	{
		word_exists = 0;
		while (s[counter] == c && s[counter] != '\0')
			counter++;
		while (s[counter] != c && s[counter] != '\0')
		{
			word_exists = 1;
			counter++;
		}
		if (word_exists == 1)
			words++;
	}
	return (words);
}

static int	get_size(char const *s, char c, int counter)
{
	int	size;

	size = 0;
	while (s[counter] == c && s[counter] != '\0')
		counter++;
	while (s[counter] != c && s[counter] != '\0')
	{
		counter++;
		size++;
	}
	return (size);
}

static char	**make_split(char **array, char c, int words, char const *s)
{
	int	size;
	int	counter;
	int	index;
	int	seccounter;

	counter = 0;
	index = 0;
	while (s[counter] != '\0' && index < words)
	{
		seccounter = 0;
		while (s[counter] == c && s[counter] != '\0')
			counter++;
		size = get_size(s, c, counter);
		array[index] = (char *) malloc ((size + 1) * sizeof(char));
		if (!array[index])
			return (NULL);
		while (s[counter] != c && s[counter] != '\0')
			array[index][seccounter++] = s[counter++];
		array[index][seccounter] = '\0';
		index++;
	}
	array[index] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**array;

	if (s == NULL)
		return (NULL);
	words = word_count(s, c);
	array = (char **) malloc ((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array = make_split(array, c, words, s);
	return (array);
}
