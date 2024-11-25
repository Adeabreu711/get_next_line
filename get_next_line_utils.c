/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:23:56 by alde-abre         #+#    #+#             */
/*   Updated: 2024/11/25 19:16:43 by alde-abre        ###   ########.fr       */
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
 * @brief Concatenate two given strings.
 * @return A pointer to a new string resulted to the concatenation of
 * the string "s1" to the string "s2".
 */

/**
 * @brief Fill the first "n" bytes of the memory area pointed to.
 * @param {void*} "s" pointer to the targeted memory location.
 * @param {int} "c" value to turn into.
 * @param {size_t} "n" size.
 * @return The given memory location ("s").
 */
void	*ft_memset(void *s, int c, size_t n)
{
	char			*str;
	unsigned int	i;

	i = -1;
	str = (char *)s;
	while (++i < n)
		str[i] = c;
	return (s);
}

/**
 * @return A pointer with "elementCount" elements with a "size" size,
 * all values are init to '\0'.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*mem;
	unsigned int	c_size;

	c_size = nmemb * size;
	if (c_size < nmemb && c_size < size)
		return (NULL);
	mem = malloc(c_size);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, c_size);
	return (mem);
}

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
