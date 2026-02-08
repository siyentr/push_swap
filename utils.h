/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:12:15 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/08 16:21:00 by mtaheri          ###   ########.fr       */
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

#endif
