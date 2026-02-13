/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:10:43 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/13 05:04:33 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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

static void	sort_more_than_4(t_node **a, t_node **b, t_config *config)
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
	sort_more_than_4(a, b, config);
}
