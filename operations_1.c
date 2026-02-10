/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:54:00 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/10 04:37:08 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	op_swap_top(a);
	op_write("sa");
}

void	sb(t_node **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	op_swap_top(b);
	op_write("sb");
}

void	ss(t_node **a, t_node **b)
{
	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	op_swap_top(a);
	op_swap_top(b);
	op_write("ss");
}

void	pa(t_node **a, t_node **b)
{
	if (!b || !*b)
		return ;
	op_push_stack(a, b);
	op_write("pa");
}

void	pb(t_node **a, t_node **b)
{
	if (!a || !*a)
		return ;
	op_push_stack(b, a);
	op_write("pb");
}
