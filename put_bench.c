/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_bench.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:12:38 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/10 20:11:07 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

long	op_total(const t_config *cfg)
{
	long	total;
	int		i;

	total = 0;
	i = 0;
	while (i < OP_COUNT)
	{
		total += cfg->op_counts[i];
		i++;
	}
	return (total);
}

static void	put_bench_header(const t_config *cfg)
{
	t_strategy	displayed;

	displayed = cfg->selected_strategy;
	if (cfg->strategy == STRAT_ADAPTIVE)
		displayed = STRAT_ADAPTIVE;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putdisorder_pct_fd(cfg->disorder, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strategy_name(displayed), 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(strategy_complexity(cfg->selected_strategy), 2);
	ft_putstr_fd("\n", 2);
}

static void	put_bench_stack_ops(const t_config *cfg)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putlong_fd(cfg->op_counts[OP_SA], 2);
	ft_putstr_fd("  sb: ", 2);
	ft_putlong_fd(cfg->op_counts[OP_SB], 2);
	ft_putstr_fd("  ss: ", 2);
	ft_putlong_fd(cfg->op_counts[OP_SS], 2);
	ft_putstr_fd("  pa: ", 2);
	ft_putlong_fd(cfg->op_counts[OP_PA], 2);
	ft_putstr_fd("  pb: ", 2);
	ft_putlong_fd(cfg->op_counts[OP_PB], 2);
	ft_putstr_fd("\n", 2);
}

static void	put_bench_rotate_ops(const t_config *cfg)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putlong_fd(cfg->op_counts[OP_RA], 2);
	ft_putstr_fd("  rb: ", 2);
	ft_putlong_fd(cfg->op_counts[OP_RB], 2);
	ft_putstr_fd("  rr: ", 2);
	ft_putlong_fd(cfg->op_counts[OP_RR], 2);
	ft_putstr_fd("  rra: ", 2);
	ft_putlong_fd(cfg->op_counts[OP_RRA], 2);
	ft_putstr_fd("  rrb: ", 2);
	ft_putlong_fd(cfg->op_counts[OP_RRB], 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_putlong_fd(cfg->op_counts[OP_RRR], 2);
	ft_putstr_fd("\n", 2);
}

void	put_bench(const t_config *cfg)
{
	put_bench_header(cfg);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putlong_fd(op_total(cfg), 2);
	ft_putstr_fd("\n", 2);
	put_bench_stack_ops(cfg);
	put_bench_rotate_ops(cfg);
}
