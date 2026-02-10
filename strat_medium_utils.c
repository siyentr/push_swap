/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_medium_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarut <ybarut@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:07:19 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/10 17:16:58 by ybarut           ###   ########.fr       */
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

