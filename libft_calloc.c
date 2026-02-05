/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_calloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:13:29 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/05 15:05:54 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memset(void *s, int c, size_t n)
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

void	*ft_calloc(size_t count, size_t size)
{
	size_t	alsize;
	void	*ptr;

	if (size != 0 && count > (size_t)-1 / size)
		return (NULL);
	alsize = count * size;
	ptr = malloc(alsize);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, alsize);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
