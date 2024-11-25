/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abre <alde-abre@42student.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:22:04 by alde-abre         #+#    #+#             */
/*   Updated: 2024/11/25 19:19:30 by alde-abre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*read_line(int fd, char *buff)
{
	char *	temp;
	int	bytes;

	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char *));
	if (!temp)
		return (NULL);
	bytes = read(fd, temp, BUFFER_SIZE);
	printf ("content : %s, bytes readed : %i\n", temp, bytes);
	buff = ft_strjoin(buff, temp);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;

	if (fd < 3 || BUFFER_SIZE == 0)
		return (NULL);
	buff = read_line(fd, buff);
	if (!buff)
		return (NULL);
	return (buff);
}

int	main()
{
	int fd = open("test", O_RDONLY);
	get_next_line(fd);

	return 0;
}
