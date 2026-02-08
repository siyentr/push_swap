/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:03:05 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/08 12:05:57 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	op_rotate_stack(a);
	op_write("ra");
}

void	rb(t_node **b)
{
	op_rotate_stack(b);
	op_write("rb");
}

void	rr(t_node **a, t_node **b)
{
	op_rotate_stack(a);
	op_rotate_stack(b);
	op_write("rr");
}

void	rra(t_node **a)
{
	op_rev_rotate_stack(a);
	op_write("rra");
}

void	rrb(t_node **b)
{
	op_rev_rotate_stack(b);
	op_write("rrb");
}
