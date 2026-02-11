/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:13:43 by mtaheri           #+#    #+#             */
/*   Updated: 2026/02/10 20:38:58 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_until_newline(int fd, char *stash)
{
	char	*buffer;
	ssize_t	number_read;
	char	*tmp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stash), NULL);
	number_read = read(fd, buffer, BUFFER_SIZE);
	while (number_read > 0)
	{
		buffer[number_read] = '\0';
		tmp = stash;
		if (stash)
			stash = ft_strjoin(stash, buffer);
		else
			stash = ft_strdup(buffer);
		free(tmp);
		if (!stash || ft_strchr(stash, '\n'))
			break ;
		number_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (number_read < 0)
		return (free(stash), NULL);
	return (stash);
}

static char	*take_line(char **stash)
{
	size_t	i;
	char	*line;
	char	*new_stash;

	if (!*stash || **stash == '\0')
		return (NULL);
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	line = ft_substr(*stash, 0, i);
	if (!line || !(*stash)[i])
		return (free(*stash), *stash = NULL, line);
	new_stash = ft_strdup(*stash + i);
	free(*stash);
	*stash = new_stash;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_until_newline(fd, stash);
	if (!stash)
		return (NULL);
	return (take_line(&stash));
}
