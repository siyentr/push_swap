/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_simple_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:00:00 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/10 20:07:19 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_top(t_node **a, int pos, int size, t_config *config)
{
	int	i;

	if (pos <= size / 2)
	{
		i = 0;
		while (i++ < pos)
			ra(a, config);
	}
	else
	{
		i = 0;
		while (i++ < (size - pos))
			rra(a, config);
	}
}

void	push_min_to_b(t_node **a, t_node **b, int size, t_config *config)
{
	t_node	*node;
	int		pos;
	int		min_pos;
	int		min_index;

	node = *a;
	min_pos = 0;
	min_index = node->index;
	pos = 0;
	while (node)
	{
		if (node->index < min_index)
		{
			min_index = node->index;
			min_pos = pos;
		}
		node = node->next;
		pos++;
	}
	rotate_to_top(a, min_pos, size, config);
	pb(a, b, config);
}
