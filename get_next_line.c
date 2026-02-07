/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:01:57 by foehler           #+#    #+#             */
/*   Updated: 2026/02/06 21:19:52 by foehler          ###   ########.fr       */
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

/**
 * @brief Extracts the head of the stash until the first '\n' or the end
 * of the stash, that is, extracts the first line.
 * 
 * @param stash The stash from which the line will be extracted.
 * @return The first line or NULL in case the stash is empty;
 */
char	*extract_line(char *stash)
{
	char	*line;
	size_t	len;

	if (!stash || stash[0] == '\0')
		return (NULL);
	len = 0;
	while (stash[len] != '\0' && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	len = 0;
	while (stash[len] != '\0' && stash[len] != '\n')
	{
		line[len] = stash[len];
		len++;
	}
	if (stash[len] == '\n')
		line[len++] = '\n';
	line[len] = '\0';
	return (line);
}

/**
 * @brief Returns the "cleaned version" of the stash, that is,
 * the substring starting at the first '\n'; and frees the stash
 * 
 * @param stash The stash which will be cleaned and freed.
 * @return The substring starting at the first '\n';
 */
char	*clean_stash(char *stash)
{
	char	*cleaned_stash;
	char	*jump;
	size_t	len;

	if (!stash || stash[0] == '\0' || !ft_strchr(stash, '\n'))
		cleaned_stash = NULL;
	else
	{
		jump = ft_strchr(stash, '\n') + 1;
		len = ft_strlen(jump);
		cleaned_stash = malloc(sizeof(char) * (len + 1));
		if (!cleaned_stash)
		{
			free(stash);
			return (NULL);
		}
		ft_strlcpy(cleaned_stash, jump, len + 1);
	}
	free(stash);
	return (cleaned_stash);
}

/**
 * @brief Returns the next line of a given file descriptor,
 * and stores the rest in a static stash.
 * 
 * @param fd The file descriptor which will be read.
 * @return The next line or NULL if it has reached the end (or
 * in case of error).
 */
char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stack(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
