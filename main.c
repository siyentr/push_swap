/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:01:03 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/10 15:13:02 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

static int	error_exit(t_node *a)
{
	write(2, "Error\n", 6);
	free_list(a);
	return (1);
}

static int	is_flag(const char *arg, const char *flag)
{
	size_t	i;

	i = 0;
	if (!arg || !flag)
		return (0);
	while (arg[i] && flag[i])
	{
		if (arg[i] != flag[i])
			return (0);
		i++;
	}
	return (arg[i] == '\0' && flag[i] == '\0');
}

static int	parse_options(int argc, char **argv, t_config *cfg, int *first_num)
{
	int	i;
	int	strategy_set;

	if (!cfg || !first_num)
		return (1);
	cfg->strategy = STRAT_ADAPTIVE;
	cfg->bench = 0;
	i = 1;
	strategy_set = 0;
	while (i < argc && argv[i] && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (is_flag(argv[i], "--bench"))
			cfg->bench = 1;
		else if (is_flag(argv[i], "--simple"))
		{
			if (strategy_set && cfg->strategy != STRAT_SIMPLE)
				return (1);
			cfg->strategy = STRAT_SIMPLE;
			strategy_set = 1;
		}
		else if (is_flag(argv[i], "--medium"))
		{
			if (strategy_set && cfg->strategy != STRAT_MEDIUM)
				return (1);
			cfg->strategy = STRAT_MEDIUM;
			strategy_set = 1;
		}
		else if (is_flag(argv[i], "--complex"))
		{
			if (strategy_set && cfg->strategy != STRAT_COMPLEX)
				return (1);
			cfg->strategy = STRAT_COMPLEX;
			strategy_set = 1;
		}
		else if (is_flag(argv[i], "--adaptive"))
		{
			if (strategy_set && cfg->strategy != STRAT_ADAPTIVE)
				return (1);
			cfg->strategy = STRAT_ADAPTIVE;
			strategy_set = 1;
		}
		else
			break ;
		i++;
	}
	*first_num = i;
	return (0);
}

static int	append_value(t_node **a, const char *arg)
{
	int		value;
	t_node	*node;

	if (parse_int(arg, &value) != 0)
		return (1);
	node = ft_lstnew(value);
	if (!node)
		return (1);
	ft_lstadd_back(a, node);
	return (0);
}

static int	build_stack(t_node **a, int argc, char **argv, int start)
{
	int		i;
	size_t	j;
	char	**parts;

	i = start;
	while (i < argc)
	{
		parts = ft_split(argv[i], ' ');
		j = 0;
		if (!parts || !parts[0])
			return (free_split_arr(parts, 0), 1);
		while (parts[j])
		{
			if (append_value(a, parts[j]) != 0)
				return (free_split_arr(parts, (int)j + 1), 1);
			j++;
		}
		free_split_arr(parts, (int)j);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_node		*a;
	t_node		*b;
	t_config	cfg;
	int			i;
	int			first_num;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (parse_options(argc, argv, &cfg, &first_num) != 0)
		return (write(2, "Error\n", 6), 1);
	if (first_num >= argc)
		return (0);
	i = 0;
	while (i < OP_COUNT)
		cfg.op_counts[i++] = 0;
	if (build_stack(&a, argc, argv, first_num) != 0)
		return (error_exit(a));
	if (has_duplicates(a))
		return (error_exit(a));
	cfg.disorder = compute_disorder(a);
	cfg.selected_strategy = resolve_strategy(cfg.strategy, cfg.disorder);
	if (is_sorted(a))
	{
		if (cfg.bench)
			put_bench(&cfg);
		return (free_list(a), 0);
	}
	if (push_swap(&a, &b, &cfg) != 0)
	{
		free_list(a);
		free_list(b);
		return (write(2, "Error\n", 6), 1);
	}
	if (cfg.bench)
		put_bench(&cfg);
	free_list(a);
	free_list(b);
	return (0);
}
