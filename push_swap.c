/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 21:34:43 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/10 13:31:55 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "utils.h"

static t_strategy	select_adaptive_strategy(t_node *a)
{
	double	disorder;

	disorder = compute_disorder(a);
	if (disorder < LOW_DISORDER_THRESHOLD)
		return (STRAT_SIMPLE);
	if (disorder < MEDIUM_DISORDER_THRESHOLD)
		return (STRAT_MEDIUM);
	return (STRAT_COMPLEX);
}

int	push_swap(t_node **a, t_node **b, t_config *config)
{
	t_strategy	selected;

	if (!a || !*a || !config)
		return (1);
	if (assign_indices(*a) != 0)
		return (1);
	selected = config->strategy;
	if (selected == STRAT_ADAPTIVE)
		selected = select_adaptive_strategy(*a);
	if (selected == STRAT_SIMPLE)
		sort_simple(a, b);
	else if (selected == STRAT_MEDIUM)
		sort_simple(a, b);
	else if (selected == STRAT_COMPLEX)
		sort_simple(a, b);
	//TOFO: medium and complex
	return (0);
}
