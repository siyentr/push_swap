/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:18:00 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/13 01:38:40 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "utils.h"

static int	get_max_bits(int size)
{
	int	max_index;
	int	bits;

	max_index = size - 1;
	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	if (bits == 0)
		return (1);
	return (bits);
}

void	sort_complex(t_node **a, t_node **b, t_config *config)
{
	int	size;
	int	bit;
	int	max_bits;
	int	i;

	size = ft_lstsize(*a);
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits && !is_sorted(*a))
	{
		i = 0;
		while (i < size)
		{
			if (((*a)->index >> bit) & 1)
				ra(a, config);
			else
				pb(a, b, config);
			i++;
		}
		while (*b)
			pa(a, b, config);
		bit++;
	}
}
