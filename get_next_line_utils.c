/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:23:56 by alde-abre         #+#    #+#             */
/*   Updated: 2024/11/28 16:54:50 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * @return The size of the given string.
 * @exception Terminating null bite ('\0') excluded.
 */
size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/**
 * @return A pointer with "elementCount" elements with a "size" size,
 * all values are init to '\0'.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*mem;
	unsigned int	c_size;
	int				i;

	i = -1;
	c_size = nmemb * size;
	if (c_size < nmemb && c_size < size)
		return (NULL);
	mem = malloc(c_size);
	if (!mem)
		return (NULL);
	while (++i < (int)c_size)
		*(unsigned char *)(mem + i) = 0;
	return (mem);
}

/**
 * @return The pointer at the first "c" int encountered in the given string "s",
 * NULL if "c" not found.
 */
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)(s + i));
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

/**
 * @param {charconst*} "s" a pointer to a string.
 * @param {unisgnedstart} "start" the start of the area to copy.
 * @param {size_t} "len" the size of the returned string.
 * @return A pointer directing to a copy of the given string "s"
 * in the given area.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dup;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || start >= 4294967295)
	{
		len = 0;
		start = 0;
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	dup[len] = '\0';
	while (len-- > 0)
		dup[len] = s[(start) + len];
	return (dup);
}

/**
 * @brief Concatenate two given strings.
 * @return A pointer to a new string resulted to the concatenation of
 * the string "s1" to the string "s2".
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	int				i;
	unsigned int	s1_len;
	unsigned int	s2_len;

	i = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	i = -1;
	while (s2[++i])
		str[s1_len + i] = s2[i];
	return (str);
}
