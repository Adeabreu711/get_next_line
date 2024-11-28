/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:22:04 by alde-abre         #+#    #+#             */
/*   Updated: 2024/11/28 17:37:26 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*freebuff(char *buff, char *temp)
{
	char	*cpy;

	cpy = buff;
	buff = ft_strjoin(cpy, temp);
	free(cpy);
	return (buff);
}

char	*get_line(char *buff, char **line)
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
	buff = ft_substr(cpy, i + 1, ft_strlen(cpy) - i + 1);
	free(cpy);
	return (buff);
}

char	*read_line(int fd, char *buff)
{
	char	*temp;
	int		bytes;

	if (!buff)
		buff = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	if (ft_strchr(buff, '\n'))
		return (buff);
	bytes = read(fd, temp, BUFFER_SIZE);
	while (bytes > 0)
	{
		buff = freebuff(buff, temp);
		if (ft_strchr(temp, '\n') || !temp || bytes < BUFFER_SIZE)
			break ;
		bytes = read(fd, temp, BUFFER_SIZE);
	}
	if (bytes == 0)
	{
		free(buff);
		buff = NULL;
	}
	free(temp);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 3 || BUFFER_SIZE == 0)
		return (NULL);
	buff = read_line(fd, buff);
	buff = get_line(buff, &line);
	return (line);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*temp;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	temp = get_next_line(fd);
	while (temp)
	{
		printf("-%s", temp);
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	return (0);
}
