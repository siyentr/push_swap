/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarut <ybarut@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:12:15 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/04 22:47:13 by ybarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "push_swap.h"

void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int has_duplicates(t_node *lst);
int is_sorted(t_node *lst);

#endif