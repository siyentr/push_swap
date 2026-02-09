/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarut <ybarut@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:12:15 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/09 16:53:40 by ybarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "push_swap.h"
# include "libft.h"

int		has_duplicates(t_node *lst);
int		is_sorted(t_node *lst);
int		parse_int(const char *str, int *out);
void	free_list(t_node *lst);
double	compute_disorder(t_node *a);

#endif
