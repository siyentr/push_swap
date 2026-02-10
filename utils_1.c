/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 21:21:56 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/10 20:15:20 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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

void	free_list(t_node *lst)
{
	t_node	*next;

	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
}

double	compute_disorder(t_node *head)
{
	long long	mistakes;
	long long	pairs;
	t_node		*left;
	t_node		*right;

	if (!head || !head->next)
		return (0.0);
	mistakes = 0;
	pairs = 0;
	left = head;
	while (left)
	{
		right = left->next;
		while (right)
		{
			pairs++;
			if (left->value > right->value)
				mistakes++;
			right = right->next;
		}
		left = left->next;
	}
	return ((double)mistakes / (double)pairs);
}

int	sqrt_num(int n)
{
	int	x;

	if (n <= 0)
		return (0);
	x = 1;
	while (x * x <= n && x < 46341)
		x++;
	return (x - 1);
}
