/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_medium_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:07:19 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/13 02:28:45 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos_in_chunk(t_node *a, int min_idx, int max_idx)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->index >= min_idx && a->index <= max_idx)
			return (pos);
		a = a->next;
		pos++;
	}
	return (-1);
}

int	find_pos_of_max(t_node *b, int *out_max_idx)
{
	int	pos;
	int	best_pos;
	int	best_idx;

	if (!b)
		return (-1);
	pos = 0;
	best_pos = 0;
	best_idx = b->index;
	while (b)
	{
		if (b->index > best_idx)
		{
			best_idx = b->index;
			best_pos = pos;
		}
		b = b->next;
		pos++;
	}
	if (out_max_idx)
		*out_max_idx = best_idx;
	return (best_pos);
}

int	medium_get_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

int	medium_get_min_pos(t_node *a)
{
	int	pos;
	int	min_idx;
	int	best_pos;

	pos = 0;
	best_pos = 0;
	min_idx = a->index;
	while (a)
	{
		if (a->index < min_idx)
		{
			min_idx = a->index;
			best_pos = pos;
		}
		a = a->next;
		pos++;
	}
	return (best_pos);
}

int	medium_target_pos_in_a(t_node *a, int b_idx)
{
	int		pos;
	int		best_pos;
	int		best_idx;
	t_node	*node;

	node = a;
	pos = 0;
	best_pos = -1;
	best_idx = 2147483647;
	while (node)
	{
		if (node->index > b_idx && node->index < best_idx)
		{
			best_idx = node->index;
			best_pos = pos;
		}
		node = node->next;
		pos++;
	}
	if (best_pos != -1)
		return (best_pos);
	return (medium_get_min_pos(a));
}
