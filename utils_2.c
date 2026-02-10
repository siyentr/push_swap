/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:12:55 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/10 20:16:45 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	insertion_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

static int	index_of(int *arr, int n, int value)
{
	int	lo;
	int	hi;
	int	mid;

	lo = 0;
	hi = n - 1;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (arr[mid] == value)
			return (mid);
		if (arr[mid] < value)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return (-1);
}

static void	fill_values_from_list(t_node *lst, int *values)
{
	int		i;
	t_node	*node;

	i = 0;
	node = lst;
	while (node)
	{
		values[i++] = node->value;
		node = node->next;
	}
}

static void	assign_indices_from_sorted(t_node *lst, int *values, int list_size)
{
	t_node	*node;

	node = lst;
	while (node)
	{
		node->index = index_of(values, list_size, node->value);
		node = node->next;
	}
}

int	assign_indices(t_node *lst)
{
	int		list_size;
	int		*values;

	list_size = ft_lstsize(lst);
	if (list_size <= 0)
		return (0);
	values = ft_calloc(list_size, sizeof(int));
	if (!values)
		return (1);
	fill_values_from_list(lst, values);
	insertion_sort(values, list_size);
	assign_indices_from_sorted(lst, values, list_size);
	free(values);
	return (0);
}
