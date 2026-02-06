/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:01:57 by foehler           #+#    #+#             */
/*   Updated: 2026/02/06 15:18:28 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Reads the file with help of the buffer and fills the stash until 
 * a '\n' is found.
 * 
 * @param fd The file descriptor.
 * @param stash The stash to be filled.
 * @return The filled stash or NULL in case of error;
 */
char	*read_and_stack(int fd, char *stash)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	read_bytes = 1;
	while ((!stash || !ft_strchr(stash, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	stash = read_and_stack(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
