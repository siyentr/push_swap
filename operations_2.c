/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:03:05 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/10 15:35:40 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a, t_config *config)
{
	if (!a || !*a || !(*a)->next)
		return ;
	op_rotate_stack(a);
	op_write("ra", config);
}

void	rb(t_node **b, t_config *config)
{
	if (!b || !*b || !(*b)->next)
		return ;
	op_rotate_stack(b);
	op_write("rb", config);
}

void	rr(t_node **a, t_node **b, t_config *config)
{
	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	op_rotate_stack(a);
	op_rotate_stack(b);
	op_write("rr", config);
}

void	rra(t_node **a, t_config *config)
{
	if (!a || !*a || !(*a)->next)
		return ;
	op_rev_rotate_stack(a);
	op_write("rra", config);
}

void	rrb(t_node **b, t_config *config)
{
	if (!b || !*b || !(*b)->next)
		return ;
	op_rev_rotate_stack(b);
	op_write("rrb", config);
}
