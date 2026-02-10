/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:14:19 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/10 04:15:48 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

void	free_split_arr(char **arr, int i)
{
	if (!arr)
		return ;
	while (i--)
		free(arr[i]);
	free(arr);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = ft_calloc(1, len + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, len);
	return (sub);
}

char	**ft_split(char const *s, char c)
{
	char		**res;
	char const	*start;
	int			i;

	if (!s)
		return (NULL);
	res = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		start = s;
		s += word_len(s, c);
		if (s > start)
		{
			res[i] = ft_substr(start, 0, s - start);
			if (!res[i])
				return (free_split_arr(res, i), NULL);
			i++;
		}
	}
	return (res);
}
