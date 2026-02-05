/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:24:11 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/05 15:09:03 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

double	get_time_in_seconds(void)
{
	return ((double)clock() / CLOCKS_PER_SEC);
}

int	main(void)
{
	const char	*cmd;
	double		start;
	double		end;

	cmd = "./push_swap 5 3 8 1 2 7 4 6";
	start = get_time_in_seconds();
	system(cmd);
	end = get_time_in_seconds();
	printf("Execution time: %f seconds\n", end - start);
	return (0);
}
