/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:22:04 by alde-abre         #+#    #+#             */
/*   Updated: 2025/01/08 14:25:31 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Free the first ptr of the given tab ** if TRUE and null assign it.
 * @return NULL.
 */
char	*safe_free(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
	return (NULL);
}

/**
 * @brief Concatenates two given strings safely.
 * @return The updated buffer with the concatenated strings.
 */
char	*join_cpy(char *buff, char *temp)
{
	char	*cpy;

	cpy = buff;
	buff = ft_strjoin(cpy, temp);
	free(cpy);
	return (buff);
}

/**
 * @brief Extracts a line from the given buffer up to the '\\n'
 * character and updates the buffer with the remaining content.
 * @return The updated buffer, or NULL if an error
 * occurs or the buffer is empty.
 */
char	*cut_line(char *buff, char **line)
{
	char	*cpy;
	int		i;

	i = -1;
	cpy = buff;
	if (!buff)
	{
		*line = NULL;
		return (NULL);
	}
	while (buff[++i])
		if (buff[i] == '\n')
			break ;
	*line = ft_substr(cpy, 0, i + 1);
	if (!*line)
		return (safe_free((void **) &cpy));
	buff = ft_substr(cpy, i + 1, ft_strlen(cpy) - i + 1);
	if (!buff)
		return (safe_free((void **) &cpy));
	free(cpy);
	return (buff);
}

/**
 * @brief Reads file content until a newline is found or EOF is reached.
 * @return The updated string buffer "buff" containing at least one line,
 * or NULL if EOF or an error occurs.
 */
char	*read_line(int fd, char *buff)
{
	char	*temp;
	int		bytes;

	if (!buff)
		return (NULL);
	if (ft_strchr(buff, '\n'))
		return (buff);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (safe_free((void **)&buff));
	bytes = read(fd, temp, BUFFER_SIZE);
	while (bytes > 0)
	{
		buff = join_cpy(buff, temp);
		if (!buff)
			return (safe_free((void **)&buff), safe_free((void **)&temp));
		if (ft_strchr(temp, '\n') || bytes < BUFFER_SIZE)
			break ;
		bytes = read(fd, temp, BUFFER_SIZE);
		temp[bytes] = 0;
	}
	if (bytes == 0 && buff[0] == '\0')
		safe_free((void **)&buff);
	free(temp);
	return (buff);
}

/**
 * @brief Read the next line from the given file descriptor "fd".
 * @return A string containing the line readead, or NULL if end of file (EOF)
 * or an error occurs.
 * @exception If this function is called with multiple file descriptors,
 * the content of the previous file is not preserved.
 */
char	*get_next_line(int fd)
{
	static char	*buff = 0;
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0 || read(fd, 0, 0) < 0)
		return (safe_free((void **)&buff));
	if (!buff)
		buff = ft_calloc(1, 1);
	buff = read_line(fd, buff);
	buff = cut_line(buff, &line);
	return (line);
}
