/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:10:43 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/10 15:36:34 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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

static void	push_min_to_b(t_node **a, t_node **b, int size, t_config *config)
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

static void	sort_2(t_node **a, t_config *config)
{
	if ((*a)->value > (*a)->next->value)
		sa(a, config);
}

static void	sort_3(t_node **a, t_config *config)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a, config);
	else if (x > y && y > z)
	{
		sa(a, config);
		rra(a, config);
	}
	else if (x > y && y < z && x > z)
		ra(a, config);
	else if (x < y && y > z && x < z)
	{
		sa(a, config);
		ra(a, config);
	}
	else if (x < y && y > z && x > z)
		rra(a, config);
}

static void	sort_4(t_node **a, t_node **b, t_config *config)
{
	push_min_to_b(a, b, 4, config);
	sort_3(a, config);
	pa(a, b, config);
}

static void	sort_5(t_node **a, t_node **b, t_config *config)
{
	int	size;

	size = ft_lstsize(*a);
	while (size > 3)
	{
		push_min_to_b(a, b, size, config);
		size--;
	}
	sort_3(a, config);
	while (*b)
		pa(a, b, config);
}

void	sort_simple(t_node **a, t_node **b, t_config *config)
{
	int	size;

	size = ft_lstsize(*a);
	if (size <= 1)
		return ;
	if (size == 2)
		return (sort_2(a, config));
	if (size == 3)
		return (sort_3(a, config));
	if (size == 4)
		return (sort_4(a, b, config));
	sort_5(a, b, config);
}
