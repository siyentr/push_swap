/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarut <ybarut@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 21:21:56 by ybarut            #+#    #+#             */
/*   Updated: 2026/02/04 22:56:39 by ybarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > (size_t)-1 / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = (unsigned char)c;
		n--;
		p++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

t_node	*ft_lstnew(int value)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	return (node);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int has_duplicates(t_node *lst)
{
    t_node *i = lst;
    t_node *temp;

    while (i)
    {
        temp = i->next;
        while (temp)
        {
            if (i->value == temp->value)
                return 1;
            temp = temp->next;
        }
        i = i->next;
    }
    return 0;
}

int is_sorted(t_node *lst)
{
    while (lst && lst->next)
    {
        if (lst->value > lst->next->value)
            return 0;
        lst = lst->next;
    }
    return 1;
}
int	ft_lstsize(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
