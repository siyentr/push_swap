/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:12:15 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/11 11:00:20 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "push_swap.h"
# include "libft.h"

int		has_duplicates(t_node *lst);
int		is_sorted(t_node *lst);
int		parse_int(const char *str, int *out);
int		parse_options(int argc, char **argv, t_config *cfg, int *first_num);
int		build_stack(t_node **a, int argc, char **argv, int start);
void	free_list(t_node *a, t_node *b);
double	compute_disorder(t_node *a);
int		assign_indices(t_node *lst);
int		sqrt_num(int n);

#endif
