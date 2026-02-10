/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:46:38 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/10 14:52:59 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_op_type(const char *op)
{
	if (!op)
		return (-1);
	if (!ft_strncmp(op, "sa", 3))
		return (OP_SA);
	if (!ft_strncmp(op, "sb", 3))
		return (OP_SB);
	if (!ft_strncmp(op, "ss", 3))
		return (OP_SS);
	if (!ft_strncmp(op, "pa", 3))
		return (OP_PA);
	if (!ft_strncmp(op, "pb", 3))
		return (OP_PB);
	if (!ft_strncmp(op, "ra", 3))
		return (OP_RA);
	if (!ft_strncmp(op, "rb", 3))
		return (OP_RB);
	if (!ft_strncmp(op, "rr", 3))
		return (OP_RR);
	if (!ft_strncmp(op, "rra", 4))
		return (OP_RRA);
	if (!ft_strncmp(op, "rrb", 4))
		return (OP_RRB);
	if (!ft_strncmp(op, "rrr", 4))
		return (OP_RRR);
	return (-1);
}

void	op_write(const char *op, t_config *config)
{
	int	type;

	type = get_op_type(op);
	if (type >= 0 && config)
		config->op_counts[type]++;
	while (*op)
	{
		write(1, op, 1);
		op++;
	}
	write(1, "\n", 1);
}

void	op_swap_top(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	op_push_stack(t_node **dst_stack, t_node **src_stack)
{
	t_node	*node;

	if (!dst_stack || !src_stack || !*src_stack)
		return ;
	node = *src_stack;
	*src_stack = node->next;
	node->next = *dst_stack;
	*dst_stack = node;
}

void	op_rotate_stack(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	op_rev_rotate_stack(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}
