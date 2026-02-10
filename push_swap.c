/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 21:34:43 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/10 02:22:38 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "utils.h"

int	push_swap(t_node **a, t_node **b, t_config *config)
{
	int	size;

	if (!a || !*a || !config)
		return (1);
	size = ft_lstsize(*a);
	if (assign_indices(*a) != 0)
		return (1);
	if (size <= 5 || config->strategy == STRAT_SIMPLE)
	{
		sort_simple(a, b);
		return (0);
	}
	return (0);
}
