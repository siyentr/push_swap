/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:32:16 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/11 10:59:48 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	is_flag(const char *arg, const char *flag)
{
	size_t	i;

	i = 0;
	if (!arg || !flag)
		return (0);
	while (arg[i] && flag[i] && arg[i] == flag[i])
		i++;
	return (arg[i] == '\0' && flag[i] == '\0');
}

static int	set_strategy(const char *arg, t_config *cfg, int *strategy_set)
{
	t_strategy	next;

	if (is_flag(arg, "--simple"))
		next = STRAT_SIMPLE;
	else if (is_flag(arg, "--medium"))
		next = STRAT_MEDIUM;
	else if (is_flag(arg, "--complex"))
		next = STRAT_COMPLEX;
	else if (is_flag(arg, "--adaptive"))
		next = STRAT_ADAPTIVE;
	else
		return (0);
	if (*strategy_set && cfg->strategy != next)
		return (-1);
	cfg->strategy = next;
	*strategy_set = 1;
	return (1);
}

int	parse_options(int argc, char **argv, t_config *cfg, int *first_num)
{
	int	i;
	int	strategy_set;
	int	status;

	cfg->strategy = STRAT_ADAPTIVE;
	cfg->bench = 0;
	i = 1;
	strategy_set = 0;
	while (i < argc && argv[i] && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (is_flag(argv[i], "--bench"))
			cfg->bench = 1;
		else
		{
			status = set_strategy(argv[i], cfg, &strategy_set);
			if (status < 0)
				return (1);
			if (status == 0)
				break ;
		}
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

int	build_stack(t_node **a, int argc, char **argv, int start)
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
