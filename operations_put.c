/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:20:58 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/10 20:23:51 by mtaheri          ###   ########.fr       */
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
	ft_putstr_fd((char *)op, 1);
	ft_putstr_fd("\n", 1);
}
