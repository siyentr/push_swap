/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:27:55 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/13 03:20:50 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "utils.h"

static void	advance_window(int *low, int *high)
{
	(*low)++;
	(*high)++;
}

static void	push_phase(t_node **a, t_node **b, int size, t_config *cfg)
{
	int	chunk_size;
	int	low;
	int	high;

	chunk_size = size / sqrt_num(size);
	if (chunk_size < 1)
		chunk_size = 1;
	low = 0;
	high = chunk_size - 1;
	while (*a)
	{
		if ((*a)->index <= low)
		{
			pb(a, b, cfg);
			rb(b, cfg);
			advance_window(&low, &high);
		}
		else if ((*a)->index <= high)
		{
			pb(a, b, cfg);
			advance_window(&low, &high);
		}
		else
			ra(a, cfg);
	}
}

static void	rotate_b_to_top(t_node **b, int pos, int size, t_config *cfg)
{
	int	i;

	if (pos <= size / 2)
	{
		i = 0;
		while (i++ < pos)
			rb(b, cfg);
	}
	else
	{
		i = 0;
		while (i++ < (size - pos))
			rrb(b, cfg);
	}
}

static void	pull_phase(t_node **a, t_node **b, t_config *cfg)
{
	int	pos;
	int	size_b;
	int	max_idx;

	while (*b)
	{
		size_b = ft_lstsize(*b);
		pos = find_pos_of_max(*b, &max_idx);
		rotate_b_to_top(b, pos, size_b, cfg);
		pa(a, b, cfg);
	}
}

void	sort_medium(t_node **a, t_node **b, t_config *config)
{
	int	size;

	if (!a || !*a)
		return ;
	size = ft_lstsize(*a);
	if (size <= 5)
		return (sort_simple(a, b, config));
	push_phase(a, b, size, config);
	pull_phase(a, b, config);
}
