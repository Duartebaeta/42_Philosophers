/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:32:40 by dhomem-d          #+#    #+#             */
/*   Updated: 2021/11/09 16:47:06 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst2;

	lst2 = *lst;
	if (*lst != NULL)
	{
		while (lst2->next != NULL)
			lst2 = lst2->next;
		lst2->next = new;
	}
	else
		*lst = new;
}
