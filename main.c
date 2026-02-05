/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:01:03 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/05 14:51:05 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

int main(int argc, char **argv)
{
	t_node *a = NULL;
	t_node *b = NULL;

	int i = 1;
	int	value;
	
	if (argc < 2)
    	return 0;
	
	while (i < argc)
	{
		if (parse_int(argv[i], &value) != 0)
			return (write(2, "Error\n", 6), 1);
		ft_lstadd_back(&a, ft_lstnew(value));
		i++;
	}
	if (has_duplicates(a))
	{
	    write(2, "Error\n", 6);
	    //free_list(a);
	    return 1;
	}
	if (is_sorted(a))
	{
	    //free_list(a);
	    return 0;
	}
	//push_swap(&a, &b);
    //free_list(a);
    //free_list(b);
	return 0;
}
