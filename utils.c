/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarut <ybarut@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 21:21:56 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/10 17:17:48 by ybarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

int	has_duplicates(t_node *lst)
{
	t_node	*i;
	t_node	*temp;

	i = lst;
	while (i)
	{
		temp = i->next;
		while (temp)
		{
			if (i->value == temp->value)
				return (1);
			temp = temp->next;
		}
		i = i->next;
	}
	return (0);
}

int	is_sorted(t_node *lst)
{
	while (lst && lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	free_list(t_node *lst)
{
	t_node	*next;

	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
}

double	compute_disorder(t_node *head)
{
	long long	mistakes;
	long long	pairs;
	t_node		*left;
	t_node		*right;

	if (!head || !head->next)
		return (0.0);
	mistakes = 0;
	pairs = 0;
	left = head;
	while (left)
	{
		right = left->next;
		while (right)
		{
			pairs++;
			if (left->value > right->value)
				mistakes++;
			right = right->next;
		}
		left = left->next;
	}
	return ((double)mistakes / (double)pairs);
}

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

//Norm: Please do not close the lights boss...

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

int	assign_indices(t_node *lst)
{
	int		list_size;
	int		array_index;
	int		*values;
	t_node	*node;

	list_size = ft_lstsize(lst);
	if (list_size <= 0)
		return (0);
	values = ft_calloc(list_size, sizeof(int));
	if (!values)
		return (1);
	node = lst;
	array_index = 0;
	while (node)
	{
		values[array_index++] = node->value;
		node = node->next;
	}
	insertion_sort(values, list_size);
	node = lst;
	while (node)
	{
		node->index = index_of(values, list_size, node->value);
		node = node->next;
	}
	free(values);
	return (0);
}

int	sqrt_num(int n)
{
	int	x;

	if (n <= 0)
		return (0);
	x = 1;
	while (x * x <= n && x < 46341)
		x++;
	return (x - 1);
}
