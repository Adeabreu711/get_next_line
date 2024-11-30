/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:22:04 by alde-abre         #+#    #+#             */
/*   Updated: 2024/11/30 01:17:37 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line_bonus.h"

char	*safe_free(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
	return (NULL);
}

char	*join_cpy(char *buff, char *temp)
{
	char	*cpy;

	cpy = buff;
	buff = ft_strjoin(cpy, temp);
	free(cpy);
	return (buff);
}

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
	if (ft_strchr(buff, '\n'))
		return (buff);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	bytes = read(fd, temp, BUFFER_SIZE);
	while (bytes > 0)
	{
		buff = join_cpy(buff, temp);
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

char	*get_next_line(int fd)
{
	static char	*buff[1024] = {0};
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0 || read(fd, 0, 0) < 0)
		return (safe_free((void **)&buff[fd]));
	buff[fd] = read_line(fd, buff[fd]);
	buff[fd] = cut_line(buff[fd], &line);
	return (line);
}

// int	main(int argc, char *argv[])
// {
// 	int		fd;
// 	char	*temp;

// 	if (argc != 2)
// 		return (0);
// 	fd = open(argv[1], O_RDONLY);
// 	temp = get_next_line(2);
// 	while (temp)
// 	{
// 		printf("-%s.\n", temp);
// 		free(temp);
// 		temp = get_next_line(fd);
// 	}
// 	printf("-%s.\n", temp);
// 	close(fd);
// 	return (0);
// }
