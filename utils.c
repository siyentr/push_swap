/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 21:21:56 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/05 15:12:01 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	has_duplicates(t_node *lst)
{
	t_node	*i;
	t_node	*temp;

	i = lst;
	while (i)
	{
		temp = i->next;
		while (temp)
		{
			if (i->value == temp->value)
				return (1);
			temp = temp->next;
		}
		i = i->next;
	}
	return (0);
}

int	is_sorted(t_node *lst)
{
	while (lst && lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}
