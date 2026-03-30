/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 21:34:43 by ybarut            #+#    #+#             */
/*   Updated: 2026/03/30 03:19:54 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "utils.h"

t_strategy	resolve_strategy(t_strategy requested, double disorder, int size)
{
	if (requested != STRAT_ADAPTIVE)
		return (requested);
	if (size <= 5)
		return (STRAT_SIMPLE);
	if (disorder < LOW_DISORDER_THRESHOLD)
		return (STRAT_SIMPLE);
	if (disorder < MEDIUM_DISORDER_THRESHOLD)
		return (STRAT_MEDIUM);
	// abi bi insan ne kadar issiz olabilir?? 
	// ne ariyon burda ne alcan ne kazancan?
	if (size <= 600)
		return (STRAT_MEDIUM);
	return (STRAT_COMPLEX);
}

const char	*strategy_name(t_strategy strategy)
{
	if (strategy == STRAT_SIMPLE)
		return ("simple");
	if (strategy == STRAT_MEDIUM)
		return ("medium");
	if (strategy == STRAT_COMPLEX)
		return ("complex");
	return ("adaptive");
}

const char	*strategy_complexity(t_strategy strategy)
{
	if (strategy == STRAT_SIMPLE)
		return ("O(n^2)");
	if (strategy == STRAT_MEDIUM)
		return ("O(n*sqrt(n))");
	if (strategy == STRAT_COMPLEX)
		return ("O(n log n)");
	return ("adaptive");
}

int	push_swap(t_node **a, t_node **b, t_config *config)
{
	t_strategy	selected;

	if (!a || !*a || !config)
		return (1);
	if (assign_indices(*a) != 0)
		return (1);
	selected = resolve_strategy(config->strategy,
			config->disorder, ft_lstsize(*a));
	config->selected_strategy = selected;
	if (selected == STRAT_SIMPLE)
		sort_simple(a, b, config);
	else if (selected == STRAT_MEDIUM)
		sort_medium(a, b, config);
	else if (selected == STRAT_COMPLEX)
		sort_complex(a, b, config);
	return (0);
}
