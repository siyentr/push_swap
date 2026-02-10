/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:27:55 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/10 17:34:24 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include "libft.h"

static void	rotate_a_to_top(t_node **a, int pos, int size, t_config *config)
{
	int	i;

	if (!a || !*a || pos < 0 || size <= 0)
		return ;
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

static void	rotate_b_to_top(t_node **b, int pos, int size, t_config *config)
{
	int	i;

	if (!b || !*b || pos < 0 || size <= 0)
		return ;
	if (pos <= size / 2)
	{
		i = 0;
		while (i++ < pos)
			rb(b, config);
	}
	else
	{
		i = 0;
		while (i++ < (size - pos))
			rrb(b, config);
	}
}

static void	push_phase(t_node **a, t_node **b, t_config *cfg, t_chunk_info info)
{
	int	current_chunk;
	int	min_idx;
	int	max_idx;
	int	pos;

	current_chunk = 0;
	while (*a && current_chunk < info.chunk_count)
	{
		min_idx = current_chunk * info.chunk_size;
		max_idx = min_idx + info.chunk_size - 1;
		if (max_idx >= info.size)
			max_idx = info.size - 1;
		pos = find_pos_in_chunk(*a, min_idx, max_idx);
		if (pos == -1)
			current_chunk++;
		else
		{
			rotate_a_to_top(a, pos, ft_lstsize(*a), cfg);
			pb(a, b, cfg);
			if ((*b)->index < (min_idx + max_idx) / 2)
				rb(b, cfg);
		}
	}
}

static void	pull_phase(t_node **a, t_node **b, t_config *cfg)
{
	int	max_pos;
	int	max_idx;
	int	size_b;

	while (*b)
	{
		size_b = ft_lstsize(*b);
		max_pos = find_pos_of_max(*b, &max_idx);
		rotate_b_to_top(b, max_pos, size_b, cfg);
		pa(a, b, cfg);
	}
}

void	sort_medium(t_node **a, t_node **b, t_config *config)
{
	int				size;
	t_chunk_info	info;

	if (!a || !*a)
		return ;
	size = ft_lstsize(*a);
	if (size <= 5)
		return (sort_simple(a, b, config));
	info.size = size;
	info.chunk_count = sqrt_num(size);
	if (info.chunk_count < 1)
		info.chunk_count = 1;
	info.chunk_size = size / info.chunk_count;
	if (size % info.chunk_count != 0)
		info.chunk_size++;
	push_phase(a, b, config, info);
	pull_phase(a, b, config);
}
