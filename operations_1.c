/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:54:00 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/08 12:07:50 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	sa(t_node **a)
{
	op_swap_top(a);
	op_write("sa");
}

void	sb(t_node **b)
{
	op_swap_top(b);
	op_write("sb");
}

void	ss(t_node **a, t_node **b)
{
	op_swap_top(a);
	op_swap_top(b);
	op_write("ss");
}

void	pa(t_node **a, t_node **b)
{
	op_push_stack(a, b);
	op_write("pa");
}

void	pb(t_node **a, t_node **b)
{
	op_push_stack(b, a);
	op_write("pb");
}
