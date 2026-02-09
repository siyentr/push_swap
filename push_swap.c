/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarut <ybarut@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 21:34:43 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/09 16:53:48 by ybarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "utils.h"

void	push_swap(t_node **a, t_node **b, t_config *config)
{
	double	disorder;

	(void)b;
	disorder = compute_disorder(*a);
	(void)config;
	(void)disorder;
}
