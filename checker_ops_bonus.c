/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:26:02 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/13 02:05:01 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	exec_op(const char *line, t_node **a, t_node **b)
{
	if (!ft_strncmp(line, "sa\n", 4) || !ft_strncmp(line, "sa", 3))
		sa(a, NULL);
	else if (!ft_strncmp(line, "sb\n", 4) || !ft_strncmp(line, "sb", 3))
		sb(b, NULL);
	else if (!ft_strncmp(line, "ss\n", 4) || !ft_strncmp(line, "ss", 3))
		ss(a, b, NULL);
	else if (!ft_strncmp(line, "pa\n", 4) || !ft_strncmp(line, "pa", 3))
		pa(a, b, NULL);
	else if (!ft_strncmp(line, "pb\n", 4) || !ft_strncmp(line, "pb", 3))
		pb(a, b, NULL);
	else if (!ft_strncmp(line, "ra\n", 4) || !ft_strncmp(line, "ra", 3))
		ra(a, NULL);
	else if (!ft_strncmp(line, "rb\n", 4) || !ft_strncmp(line, "rb", 3))
		rb(b, NULL);
	else if (!ft_strncmp(line, "rrr\n", 5) || !ft_strncmp(line, "rrr", 4))
		rrr(a, b, NULL);
	else if (!ft_strncmp(line, "rra\n", 5) || !ft_strncmp(line, "rra", 4))
		rra(a, NULL);
	else if (!ft_strncmp(line, "rrb\n", 5) || !ft_strncmp(line, "rrb", 4))
		rrb(b, NULL);
	else if (!ft_strncmp(line, "rr\n", 4) || !ft_strncmp(line, "rr", 3))
		rr(a, b, NULL);
	else
		return (1);
	return (0);
}
