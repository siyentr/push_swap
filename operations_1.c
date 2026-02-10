/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:54:00 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/10 15:35:31 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a, t_config *config)
{
	if (!a || !*a || !(*a)->next)
		return ;
	op_swap_top(a);
	op_write("sa", config);
}

void	sb(t_node **b, t_config *config)
{
	if (!b || !*b || !(*b)->next)
		return ;
	op_swap_top(b);
	op_write("sb", config);
}

void	ss(t_node **a, t_node **b, t_config *config)
{
	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	op_swap_top(a);
	op_swap_top(b);
	op_write("ss", config);
}

void	pa(t_node **a, t_node **b, t_config *config)
{
	if (!b || !*b)
		return ;
	op_push_stack(a, b);
	op_write("pa", config);
}

void	pb(t_node **a, t_node **b, t_config *config)
{
	if (!a || !*a)
		return ;
	op_push_stack(b, a);
	op_write("pb", config);
}
