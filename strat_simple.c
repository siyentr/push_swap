/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:10:43 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/10 04:15:31 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

// find_max: 0 -> min index, 1 -> max value
static int	find_extreme_pos(t_node *a, int find_max)
{
	int	pos;
	int	best_pos;
	int	best_value;

	pos = 0;
	best_pos = 0;
	if (find_max)
		best_value = a->value;
	else
		best_value = a->index;
	while (a)
	{
		if ((!find_max && a->index < best_value)
			|| (find_max && a->value > best_value))
		{
			if (find_max)
				best_value = a->value;
			else
				best_value = a->index;
			best_pos = pos;
		}
		a = a->next;
		pos++;
	}
	return (best_pos);
}

static void	rotate_to_top(t_node **a, int pos, int size)
{
	int	i;

	if (pos <= size / 2)
	{
		i = 0;
		while (i++ < pos)
			ra(a);
	}
	else
	{
		i = 0;
		while (i++ < (size - pos))
			rra(a);
	}
}

static void	push_min_to_b(t_node **a, t_node **b, int size)
{
	int	min_pos;

	min_pos = find_extreme_pos(*a, 0);
	rotate_to_top(a, min_pos, size);
	pb(a, b);
}

static void	sort_2(t_node **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

static void	sort_3(t_node **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

static void	sort_4(t_node **a, t_node **b)
{
	push_min_to_b(a, b, 4);
	sort_3(a);
	pa(a, b);
}

static void	sort_5(t_node **a, t_node **b)
{
	int	size;

	size = ft_lstsize(*a);
	while (size > 3)
	{
		push_min_to_b(a, b, size);
		size--;
	}
	sort_3(a);
	while (*b)
		pa(a, b);
}

void	sort_simple(t_node **a, t_node **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size <= 1)
		return ;
	if (size == 2)
		return (sort_2(a));
	if (size == 3)
		return (sort_3(a));
	if (size == 4)
		return (sort_4(a, b));
	sort_5(a, b);
}
