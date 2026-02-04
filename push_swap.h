/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarut <ybarut@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:23:44 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/04 21:46:05 by ybarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stddef.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct s_node
{
    int             value;
    int             index;
    int             pos;
    int             target_pos;
    int             cost_a;
    int             cost_b;
    struct s_node   *next;
}   t_node;

t_node	*ft_lstnew(int value);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);

#endif