/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarut <ybarut@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:23:44 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/10 17:16:34 by ybarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include "libft.h"

#define LOW_DISORDER_THRESHOLD 0.2
#define MEDIUM_DISORDER_THRESHOLD 0.5

typedef enum e_strategy
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE
}	t_strategy;

typedef enum e_op_type
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_op_type;

typedef struct s_config
{
	t_strategy	strategy;
	t_strategy	selected_strategy;
	double		disorder;
	long		op_counts[OP_COUNT];
	int			bench;
}	t_config;

int		push_swap(t_node **a, t_node **b, t_config *config);
t_strategy	resolve_strategy(t_strategy requested, double disorder);
const char	*strategy_name(t_strategy strategy);
const char	*strategy_complexity(t_strategy strategy);

void	sort_simple(t_node **a, t_node **b, t_config *config);
void	sort_medium(t_node **a, t_node **b, t_config *config);
int		find_pos_in_chunk(t_node *a, int min_idx, int max_idx);
int		find_pos_of_max(t_node *b, int *out_max_idx);

void	op_write(const char *op, t_config *config);
void	op_swap_top(t_node **stack);
void	op_push_stack(t_node **dst, t_node **src);
void	op_rotate_stack(t_node **stack);
void	op_rev_rotate_stack(t_node **stack);
long	op_total(const t_config *cfg);

void	put_bench(const t_config *cfg);

void	sa(t_node **a, t_config *config);
void	sb(t_node **b, t_config *config);
void	ss(t_node **a, t_node **b, t_config *config);
void	pa(t_node **a, t_node **b, t_config *config);
void	pb(t_node **a, t_node **b, t_config *config);
void	ra(t_node **a, t_config *config);
void	rb(t_node **b, t_config *config);
void	rr(t_node **a, t_node **b, t_config *config);
void	rra(t_node **a, t_config *config);
void	rrb(t_node **b, t_config *config);
void	rrr(t_node **a, t_node **b, t_config *config);

#endif
