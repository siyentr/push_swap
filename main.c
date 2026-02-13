/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:01:03 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/13 05:06:53 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	error_exit(t_node *a, t_node *b)
{
	write(2, "Error\n", 6);
	free_list(a, b);
	return (1);
}

static void	init_op_counts(t_config *cfg)
{
	int	i;

	i = 0;
	while (i < OP_COUNT)
	{
		cfg->op_counts[i] = 0;
		i++;
	}
}

static int	prepare_data(int argc, char **argv, t_node **a, t_config *cfg)
{
	int	first_num;

	if (parse_options(argc, argv, cfg, &first_num) != 0)
		return (1);
	if (first_num >= argc)
		return (2);
	init_op_counts(cfg);
	if (build_stack(a, argc, argv, first_num) != 0 || has_duplicates(*a))
		return (-1);
	cfg->disorder = compute_disorder(*a);
	cfg->selected_strategy = resolve_strategy(cfg->strategy,
			cfg->disorder, ft_lstsize(*a));
	return (0);
}

static int	finish_sorted(t_node *a, t_config *cfg)
{
	if (cfg->bench)
		put_bench(cfg);
	free_list(a, NULL);
	return (0);
}

int	main(int argc, char **argv)
{
	t_node		*a;
	t_node		*b;
	t_config	cfg;
	int			state;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	state = prepare_data(argc, argv, &a, &cfg);
	if (state == 1)
		return (error_exit(NULL, NULL));
	if (state == 2)
		return (0);
	if (state == -1)
		return (error_exit(a, NULL));
	if (is_sorted(a))
		return (finish_sorted(a, &cfg));
	if (push_swap(&a, &b, &cfg) != 0)
		return (error_exit(a, b));
	if (cfg.bench)
		put_bench(&cfg);
	return (free_list(a, b), 0);
}
