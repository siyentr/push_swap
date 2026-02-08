/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:01:03 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/08 16:25:03 by mtaheri          ###   ########.fr       */
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

static int	build_stack(t_node **a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (append_value(a, argv[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	(void)b;
	if (argc < 2)
		return (0);
	if (build_stack(&a, argc, argv) != 0)
		return (error_exit(a));
	if (has_duplicates(a))
		return (error_exit(a));
	if (is_sorted(a))
		return (free_list(a), 0);
	push_swap(&a, &b);
	free_list(a);
	free_list(b);
	return (0);
}
