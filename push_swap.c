/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarut <ybarut@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 21:34:43 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/04 21:57:00 by ybarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_node *a = NULL;
	t_node *b = NULL;

	int i = 1;
	
	while (i < argc)
	{
		ft_lstadd_back(&a,ft_lstnew(atoi(argv[i])));
		i++;
	}
	return 0;
}
