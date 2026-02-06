/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:01:59 by foehler           #+#    #+#             */
/*   Updated: 2026/02/06 15:17:51 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Calculates the length of a string.
 * 
 * @param s The string to measure.
 * @return The number of characters in the string.
 */
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * @brief Concatenates two strings into a new string (it handles NULLs).
 * In addition, it frees the first string.
 * 
 * @param s1 The first string.
 * @param s2 The second string.
 * @return The newly allocated concatenated string (or a copy of s2, if s1 
 * is NULL), or NULL on failure.
 */
char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*str;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2));
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

/**
 * @brief Locates the first occurrence of a character in a string.
 * 
 * @param s The string to search.
 * @param c The character to locate.
 * @return Pointer to the first occurrence of c, or NULL if not found.
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == 0)
		return ((char *)s);
	else
		return (NULL);
}

/**
 * @brief Copies a string with size limit.
 * 
 * @param dst The destination buffer.
 * @param src The source string.
 * @param size Size of the destination buffer.
 * @return The total length of the source string.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/**
 * @brief Copies memory area.
 * 
 * @param dest Pointer to the destination.
 * @param src Pointer to the source.
 * @param n Number of bytes to copy.
 * @return Pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		temp_dest[i] = temp_src[i];
		i++;
	}
	return (dest);
}
