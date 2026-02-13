/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:46:16 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/13 02:05:11 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "utils.h"

static int	error_exit(t_node *a, t_node *b, char *line)
{
	free(line);
	free_list(a, b);
	write(2, "Error\n", 6);
	return (1);
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

static int	build_checker_stack(t_node **a, int argc, char **argv)
{
	int		i;
	size_t	j;
	char	**parts;

	i = 1;
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

static int	run_instructions(t_node **a, t_node **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (exec_op(line, a, b) != 0)
			return (error_exit(*a, *b, line));
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(*a) && !*b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (build_checker_stack(&a, argc, argv) != 0 || has_duplicates(a))
		return (error_exit(a, b, NULL));
	if (run_instructions(&a, &b) != 0)
		return (1);
	free_list(a, b);
	return (0);
}
